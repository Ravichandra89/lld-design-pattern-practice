#ifndef EURO_TAX_STRATEGY_HPP
#define EURO_TAX_STRATEGY_HPP

#include "TaxStrategy.hpp"

class EuTaxStrategy : public TaxStrategy {
    public:
        double calculateTax(double amount) const override {
            const double taxRate = 0.20;
            return amount * taxRate;
        }
};

#endif