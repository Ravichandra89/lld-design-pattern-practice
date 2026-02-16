#ifndef DINEORDER_HPP
#define DINEORDER_HPP

#include "IBaseOrder.hpp"
#include "../entities/Entities.hpp"
#include "../utils/IdGenerator.hpp"
#include "../utils/utils.hpp"

using namespace std;

class DineOrder : public IBaseOrder
{
public:
    Order create(const string &customerId, const vector<pair<MenuItem, int>> &items, const string idempotencyKey = "") override
    {
        Order o;
        o.id = IdGenerator::next("DIN-");
        o.customer_id = customerId;
        o.status = "PLACED";
        o.type = "DINE_IN";
        o.created_at = Utils::now();

        for (const auto &it : items)
        {
            OrderItem orderItem;
            orderItem.menu_item_id = it.first.id;
            orderItem.name = it.first.name;   
            orderItem.price = it.first.price; 
            orderItem.quantity = it.second;

            o.items.push_back(orderItem);
        }

        return o;
    }
};

#endif
