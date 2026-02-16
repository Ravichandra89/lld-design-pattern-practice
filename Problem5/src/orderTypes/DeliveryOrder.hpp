#ifndef DELIVERY_HPP
#define DELIVERY_HPP

#include "IBaseOrder.hpp"
#include "../entities/Entities.hpp"
#include "../repository/repo.hpp"

using namespace std;

class DeliveryOrder : public IBaseOrder
{
public:
    Order create(const string &customerId, const vector<pair<MenuItem, int>> &items, const string idempotencyKey = "") override
    {
        Order o;
        o.id = IdGenerator::next("ONL-"); // prefix for delivery/online orders
        o.customer_id = customerId;
        o.created_at = chrono::system_clock::now();
        o.status = "PLACED";
        o.payment_status = "PENDING";
        o.idempotency_key = idempotencyKey;

        double total = 0.0;
        for (auto &p : items)
        {
            OrderItem oi;
            oi.id = IdGenerator::next("OI-");
            oi.order_id = o.id;
            oi.menu_item_id = p.first.id;
            oi.quantity = p.second;
            oi.unit_price = p.first.price;
            oi.status = "PENDING";
            o.items.push_back(oi);
            total += oi.unit_price * oi.quantity;
        }

        o.total_amount = total;
        o.type = "DELIVERY"; 
        return o;
    }
};

#endif
