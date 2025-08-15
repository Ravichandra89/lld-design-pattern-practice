/**
 * Tax Strategy Interface 
 */
#ifndef ECOMMERCE_TAX_STRATEGY_HPP
#define ECOMMERCE_TAX_STRATEGY_HPP

#include <string>

class TaxStrategy {
    public: 
        // Destructor
        virtual ~TaxStrategy() = default;
        virtual double calculateTax(double amount) const = 0;
};

#endif