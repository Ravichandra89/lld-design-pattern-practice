#ifndef US_DOLLAR_TAX_STRATEGY_HPP
#define US_DOLLAR_TAX_STRATEGY_HPP

#include "TaxStrategy.hpp"
#include <string>
using namespace std;

class DollarTaxStrategy : public TaxStrategy {
    public: 
        double calculateTax(double amount) const override {
            const double rate = 0.08;
            return amount * rate;
        }
};

#endif