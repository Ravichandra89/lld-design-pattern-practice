/**
 * BaseOrder Interface for further orders
 */
#ifndef IBASE_ORDER_HPP
#define IBASE_ORDER_HPP

#include "../entities/Entities.hpp"
#include <string>
using namespace std;

class IBaseOrder {
    public: 
        virtual ~IBaseOrder() = default;
        virtual Order create(const string& customerId, const vector<pair<MenuItem, int>> &items, const string idempotencyKey = "") = 0;
};

#endif