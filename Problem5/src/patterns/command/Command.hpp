/**
 * Request -> Stand alone object conversion
 * seperation of sender and reciever
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../../entities/Entities.hpp"
#include "../../repository/repo.hpp"
#include "../factory/paymentFactory.hpp"
#include "../observer/IObserver.hpp"

#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

class ICommand {
    public: 
        virtual ~ICommand() = default;
        virtual bool execute() = 0;
};

// 1st command #placeOrder
class PlaceOrder : public ICommand {
    Order o;
    MenuRepository &menu_repo;
    OrderRepository &ord_repo;
    InventoryRepository &inv_repo;
    vector<shared_ptr<IObserver>> observers;
    string method;

public:
    // Constructor
    PlaceOrder(Order o,
               MenuRepository &menu_repo,
               OrderRepository &ord_repo,
               InventoryRepository &inv_repo,
               const vector<shared_ptr<IObserver>> &obs,
               const string &method)
        : o(move(o)),
          menu_repo(menu_repo),
          ord_repo(ord_repo),
          inv_repo(inv_repo),
          observers(obs),
          method(method)
    {}

    bool execute() override {
        // 1. Reserving Inventory
        for (auto &i : o.items) {
            auto miOpt = menu_repo.get(i.menu_item_id);
            if (!miOpt) {
                cout << "Menu item not found: " << i.menu_item_id << endl;
                return false;
            }

            auto invOpt = inv_repo.getByItem(i.menu_item_id);
            if (invOpt) {
                if (!inv_repo.reserve(i.menu_item_id, i.quantity)) {
                    cout << "Insufficient inventory for " << i.menu_item_id << endl;

                    for (auto &r : o.items) {
                        if (r.menu_item_id == i.menu_item_id)
                            break;
                        inv_repo.release(r.menu_item_id, r.quantity);
                    }

                    return false;
                }
            }
        }

        // 2. Save the order
        ord_repo.add(o);

        // 3. Make Payment
        auto paymentInitiate = paymentFactory::create(method);
        bool paid = paymentInitiate->pay(o.id, o.total_amount);
        o.payment_status = paid ? "SUCCESS" : "FAILED";
        ord_repo.add(o);

        // 4. Notify Observers
        for (auto &it : observers) {
            if (it)
                it->onNotify(o.id, "Order Placed: payment=" + o.payment_status);
        }

        return paid;
    }
};


// 2nd Command #CancelOrder
class CancelOrder : public ICommand {
        string orderId;
        OrderRepository &ord_repo;
        InventoryRepository & inv_repo;

    public: 
        CancelOrder(const string& orderId, OrderRepository &ord_repo, InventoryRepository &inv_repo) : orderId(orderId), ord_repo(ord_repo), inv_repo(inv_repo){};

        bool execute() override {
            auto oit = ord_repo.get(orderId);
            if (!oit) return false;
            Order o = *oit;
            if (o.status == "COMPLETED" || o.status == "CANCELLED") return false;
            for (auto & i : o.items) inv_repo.release(i.menu_item_id, i.quantity);
            o.status = "CANCELLED";
            ord_repo.add(o); 
            cout << "Order " << orderId << " cancelled " << endl;

            return true;
        }
};


// 
#endif