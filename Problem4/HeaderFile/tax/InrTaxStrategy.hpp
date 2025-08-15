#ifndef INR_TAX_STRATEGY_CONCRETE_HPP
#define INR_TAX_STRATEGY_CONCRETE_HPP

#include "TaxStrategy.hpp";
#include <string>

using namespace std;

class InrTaxStrategy : public TaxStrategy {
    public: 
        double calculateTax(double amount) const override {
            const double taxRate = 0.18;
            return amount * taxRate;
        }
};


#endif