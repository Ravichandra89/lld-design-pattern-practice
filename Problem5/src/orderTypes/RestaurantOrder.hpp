/**
 * RestaurantOrder.hpp
 * Base implementation of an order placed in a restaurant
 */

#ifndef RESTAURANTORDER_HPP
#define RESTAURANTORDER_HPP

#include "IBaseOrder.hpp"
#include "../entities/Entities.hpp"
#include "../utils/IdGenerator.hpp"
#include "../utils/utils.hpp"

using namespace std;

class RestaurantOrder : public IBaseOrder
{
protected:
    string orderType;

public:
    RestaurantOrder(const string &type) : orderType(type) {}

    Order create(const string &customerId, const vector<pair<MenuItem, int>> &items, const string idempotencyKey = "") override
    {
        Order o;
        o.id = IdGenerator::next(orderType.substr(0, 3) + "-"); 
        o.customer_id = customerId;
        o.status = "PLACED";
        o.type = orderType;
        o.created_at = Utils::now();

        // Convert (MenuItem, qty) -> OrderItem
        for (const auto &it : items)
        {
            OrderItem orderItem;
            orderItem.id = IdGenerator::next("OI-");
            orderItem.menu_item_id = it.first.id;
            orderItem.quantity = it.second;
            orderItem.unit_price = it.first.price;

            o.items.push_back(orderItem);
        }

        // calculate total amount
        double total = 0.0;
        for (auto &oi : o.items)
        {
            total += oi.unit_price * oi.quantity;
        }
        o.total_amount = total;

        o.idempotency_key = idempotencyKey;

        return o;
    }
};

#endif
