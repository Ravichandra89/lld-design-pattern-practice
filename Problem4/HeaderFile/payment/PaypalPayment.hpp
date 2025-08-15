#ifndef PAYPAL_PAYMENT_HPP
#define PAYPAL_PAYMENT_HPP

#include "Payment.hpp"
#include <string>
#include <iostream>

using namespace std;

class PaypalPayment : public Payment {
    string email;
    string password;

    public: 
        // Constructor to initialize PayPal payment
        PaypalPayment(const string& email, const string& password) : email(email), password(password) {}

        bool pay(double amount) const override {
            cout << "Processing PayPal payment of $" << amount << endl;
            cout << "Email: " << email << endl;
            // Simulate payment processing
            return true; // Assuming payment is successful
        }

        // TODO: Implement additional methods if needed, such as for handling payment confirmation or error handling.
};

#endif