#ifndef CONCRETE_WALLET_PAYMENT_HPP
#define CONCRETE_WALLET_PAYMENT_HPP

#include "IPayment.hpp"
#include <iostream>

using namespace std;

class WalletPayment : public IPayment {
    public: 
        bool processPayment(double amount, const string& tripId) override {
            cout << "[Wallet Payment] charge " << amount << " for " << tripId << endl;
        }
};

#endif