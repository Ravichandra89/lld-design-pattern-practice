/**
 * Delivery_Interface
 */
#ifndef DELIVERY_BRIDGE_INTERFACE_HPP
#define DELIVERY_BRIDGE_INTERFACE_HPP

#include <string>
using namespace std;

class IDelivery {
    public: 
        virtual ~IDelivery() = default;
        virtual void deliver(const string& mediaPath) = 0;
};

#endif