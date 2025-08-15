#ifndef PAYMENT_FACTORY_HPP
#define PAYMENT_FACTORY_HPP

#include "Payment.hpp"
#include "CreditCard.hpp"
#include "PaypalPayment.hpp"
#include "UpiPayment.hpp"

#include <memory>
#include <string>
#include <iostream>
using namespace std;

class PaymentFactory {
    public: 
        static unique_ptr<PaymentKaro> createPayment(const string& type) {
            if (type == "CreditCard") {
                return make_unique<CreditCard>("123456789012345", "John Doe", "12/25", "123");
            }
            if (type == "Paypal") {
                return make_unique<PaypalPayment>("ravi@gmail.com", "password123");
            }
            if (type == "UPI") {
                return make_unique<UpiPayment>("ravi@upi", "Ravi Chandra");
            }

            cout << "Unknown payment type: " << type << "Please Try Again With (CreditCard/Paypal/Upi Payment)" << endl;
        } 
};

#endif