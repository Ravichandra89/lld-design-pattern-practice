#ifndef DELIVERY_ABSTRACT_HPP
#define DELIVERY_ABSTRACT_HPP

#include "../Implementor/Interface.hpp"

class DeliveryAbstract {
    protected : 
        unique_ptr<IDelivery> impl;

    public: 
        // Constructor 
        DeliveryAbstract(IDelivery* implementor) : impl(implementor) {}
        virtual ~DeliveryAbstract() = default;

        virtual void send(const string& mediaPath) {
            impl->deliver(mediaPath);
        }
};

#endif