#ifndef ORDER_FACTORY_HPP
#define ORDER_FACTORY_HPP

#include "../../orderTypes/DeliveryOrder.hpp"
#include "../../orderTypes/DineOrder.hpp"
#include "../../orderTypes/RestaurantOrder.hpp"
#include "../../orderTypes/IBaseOrder.hpp"

#include <memory>
#include <iostream>
using namespace std;


class orderFactory {
    public: 
        unique_ptr<IBaseOrder> create(const string& orderType) {
            if (orderType == "ONLINE") return make_unique<DeliveryOrder> ();
            if (orderType == "DINE") return make_unique<DineOrder> ();
            if (orderType == "RESTAURANT") return make_unique<RestaurantOrder> ();

            cout << "Choosed order Type not supported" << endl;
        }
};

#endif