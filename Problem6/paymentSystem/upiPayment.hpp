#ifndef CONCRETE_UPI_PAYMENT_HPP
#define CONCRETE_UPI_PAYMENT_HPP

#include "IPayment.hpp"
#include <iostream>
using namespace std;

class UPIPayment : public IPayment {
    public: 
        bool processPayment(double amount, const string& tripId) override {
            cout << "[UPI Payment] charged " << amount << " for " << tripId << endl;
        }
};

#endif