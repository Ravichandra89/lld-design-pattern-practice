#ifndef CONCRETE_CARD_PAYMENT_HPP
#define CONCRETE_CARD_PAYMENT_HPP

#include "IPayment.hpp"
#include <iostream>
using namespace std;

class CardPayment : public IPayment {
    public: 
        bool processPayment(double amount, const string& tripId) override {
            cout << "[Card Payment] charged " << amount << " for " << tripId << endl;
            return true;
        }
};

#endif