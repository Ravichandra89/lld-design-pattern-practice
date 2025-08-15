/**
 * Payment System using Factory Design Pattern
 */
#ifndef PAYMENT_INTERFACE_HPP
#define PAYMENT_INTERFACE_HPP

#include <string>
#include <memory>

using namespace std;

class PaymentKaro {
    public: 
        virtual ~PaymentKaro() = default;
        virtual bool pay(double amount) const = 0;
};

#endif