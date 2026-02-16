/**
 * IdGenerator()
 * MenuRepository:
 *  - add()
 *  - get()
 *  - all()
 *  - decrementIfAvailable()
 *
 * OrderRepository:
 *  - add()
 *  - get()
 *  - findByIdempotency()
 *
 * InventoryRepository:
 *  - set()
 *  - getByItem()
 *  - reserve()
 *  - release()
 */

#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include "../entities/Entities.hpp"
#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>
#include <mutex>
#include <atomic>

#include "../utils/IdGenerator.hpp"

using namespace std;


// MenuRepository
class MenuRepository
{
    unordered_map<string, MenuItem> items;
    mutex mtx;

public:
    void add(const MenuItem &item)
    {
        // Double locking to avoid
        lock_guard<mutex> lock(mtx);
        items[item.id] = item;
    }

    optional<MenuItem> get(const string &id)
    {
        lock_guard<mutex> lock(mtx);

        // search for the item
        if (items.find(id) == items.end())
        {
            return nullopt;
        }
        return items[id];
    }

    // return all items
    vector<MenuItem> all()
    {
        lock_guard<mutex> lock(mtx);
        vector<MenuItem> result;
        result.reserve(items.size());
        for (const auto &it : items)
        {
            result.push_back(it.second);
        }
        return result;
    }

    // decrement available quantity if available
    bool decrementIfAvailable(const string &id, int qty)
    {
        lock_guard<mutex> lock(mtx);
        auto it = items.find(id);
        if (it == items.end())
        {
            return false;
        }

        // check availability
        if (!it->second.is_available)
        {
            return false;
        }
        if (it->second.available_qty != -1 && it->second.available_qty < qty)
        {
            return false;
        }

        // decrement quantity
        if (it->second.available_qty != -1)
        {
            it->second.available_qty -= qty;
        }

        return true;
    }
};

class OrderRepository
{
    unordered_map<string, Order> orders;
    mutex mtx;
    unordered_map<string, string> idempotency_ind;

public:
    // add method
    void add(const Order &order)
    {
        lock_guard<mutex> lock(mtx);
        orders[order.id] = order;
        if (!order.idempotency_key.empty())
        {
            idempotency_ind[order.idempotency_key] = order.id;
        }
    }

    // getOrder optional
    optional<Order> get(const string &orderId)
    {
        lock_guard<mutex> lock(mtx);
        if (orders.find(orderId) == orders.end())
        {
            return nullopt;
        }

        return orders[orderId];
    }

    // Find Order by Idempotency - using key
    optional<Order> findByIdempotency(const string &key)
    {
        lock_guard<mutex> lock(mtx);
        auto it = idempotency_ind.find(key);
        if (it == idempotency_ind.end())
        {
            return nullopt;
        }

        auto orderIt = orders.find(it->second);
        if (orderIt == orders.end())
        {
            return nullopt;
        }

        return orderIt->second;
    }
};

class InventoryRepository {
    unordered_map<string, Inventory> inv;
    mutex mtx;

    public: 
        void set(const Inventory& v) {
            lock_guard<mutex> lock(mtx);
            inv[v.menu_item_id] = v;
        }

        // getByItem
        optional<Inventory> getByItem(const string& menuItemId) {
            lock_guard<mutex> lock(mtx);
            if (inv.find(menuItemId) == inv.end()){
                return nullopt;
            }

            return inv[menuItemId];
        }

        // reserve()
        bool reserve(const string& menuItemId, int qty) {
            lock_guard<mutex> lock(mtx);
            auto it = inv.find(menuItemId);
            if (it == inv.end()) return false;
            
            Inventory& i = it->second;
            if (i.available_qty - i.reserved_qty >= qty) {
                i.reserved_qty += qty;
                i.updated_at = chrono::system_clock::now();
                return true;
            }
            return false;
        }

        void release(const string & menuItemId, int qty) {
            lock_guard<mutex> lock(mtx);
            auto it = inv.find(menuItemId);
            if (it == inv.end()) return;

            Inventory & i = it->second;
            i.reserved_qty = max(0, i.reserved_qty - qty);
            i.updated_at = chrono::system_clock::now();
        }
};

#endif