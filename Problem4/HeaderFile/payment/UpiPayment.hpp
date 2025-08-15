#ifndef UPI_PAYMENT_HPP
#define UPI_PAYMENT_HPP

#include "Payment.hpp"
#include <string>
#include <iostream>

using namespace std;

class UpiPayment : public Payment {
    string upiId;
    string name;

    public: 
        // Constructor to initialize UPI payment
        UpiPayment(const string& upiId, const string& name) : upiId(upiId), name(name) {}

        bool pay(double amount) const override {
            cout << "Processing UPI payment of $" << amount << endl;
            cout << "UPI ID: " << upiId << endl;
            cout << "Name: " << name << endl;
            // Simulate payment processing
            return true; // Assuming payment is successful
        }
};

#endif