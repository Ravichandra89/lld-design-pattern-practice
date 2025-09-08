#ifndef PAYMENT_FACTORY_HPP
#define PAYMENT_FACTORY_HPP

#include "IPayment.hpp"
#include "cardPayment.hpp"
#include "upiPayment.hpp"
#include "walletPayment.hpp"
#include <memory>
using namespace std;

class PaymentFactory{
    public: 
         unique_ptr<IPayment> create(const string& method) {
            if (method == "card") return make_unique<CardPayment>();
            if (method == "upi") return make_unique<UPIPayment> ();
            if (method == "wallet") return make_unique<WalletPayment> ();
            return nullptr;
        }
};
#endif