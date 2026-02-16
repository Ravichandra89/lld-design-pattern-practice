#ifndef PAYMENT_STRATEGY_HPP
#define PAYMENT_STRATEGY_HPP

#include <string>
#include <iostream>

using namespace std;

// Strategy interface
class IPaymentStrategy
{
public:
    virtual ~IPaymentStrategy() = default; 
    virtual bool pay(const string &orderId, double amount) = 0;
    virtual string name() const = 0;
};

// Concrete strategy: Card Payment
class CardPayment : public IPaymentStrategy
{
    string cardNumber;

public:
    // constructor
    explicit CardPayment(const string &cardNumber) : cardNumber(cardNumber) {}

    bool pay(const string &orderId, double amount) override
    {
        cout << "[CardPayment] Charging " << amount
             << " for order " << orderId
             << " using card ending "
             << (cardNumber.size() > 4 ? cardNumber.substr(cardNumber.size() - 4) : cardNumber)
             << endl;
        return true;
    }

    string name() const override
    {
        return "CardPayment";
    }
};

// Concrete Strategy : CashPayment
class CashPayment : public IPaymentStrategy {
    public: 
        CashPayment() {}
        bool pay(const string& orderId, double amount) override {
            cout << "[CashPayment] Charging " << amount << " for Order " << orderId << endl;  
        }

        string name() const override {
            return "CashPayment";
        }
};

class UPIPayment : public IPaymentStrategy {
        string upiId;
    
    public: 
        // constructor
        explicit UPIPayment(const string& upiId) : upiId(upiId) {}

        bool pay(const string& orderId, double amount) override {
            cout << "[UPIPayment] Charging " << amount << " for Order " << orderId << endl;
        }

        string name() const override {
            return "UPIPayment";
        }
};

#endif 
