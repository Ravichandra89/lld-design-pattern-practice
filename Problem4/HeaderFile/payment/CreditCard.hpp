#ifndef CREDIT_CARD_HPP
#define CREDIT_CARD_HPP

#include "Payment.hpp"
#include <string>
#include <iostream>
using namespace std;

class CreditCard : public Payment {
        string cardNumber;
        string name;
        string expiryDate;
        string cvv;

    public: 
        // Constructor to initialize credit card
        CreditCard(const string& cardNumber, const string& name, const string& expiryDate, const string& cvv) : cardNumber(cardNumber), name(name), expiryDate(expiryDate), cvv(cvv) {};

        bool pay(double amount) const override {
            cout << "Processing credit card payment of $" << amount << endl;
            cout << "Card Number: " << cardNumber << endl;
            cout << "Name: " << name << endl;
            cout << "Expiry Date: " << expiryDate << endl;

            return true;
        }
};

#endif