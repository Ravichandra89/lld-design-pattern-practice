#ifndef PAYMENT_FACTORY_HPP
#define PAYMENT_FACTORY_HPP

#include "../strategy/paymentStrategy.hpp"
#include <string>
#include <memory>
using namespace std;

// Factorcy class
class paymentFactory {
    public: 
        static unique_ptr<IPaymentStrategy> create(const string& type) {
            if (type == "CARD") return make_unique<CardPayment>("123456789");
            if (type == "UPI") return make_unique<UPIPayment> ("8737937@ybl");

            // default CashPayment
            return make_unique<CashPayment> ();
        }
};

#endif