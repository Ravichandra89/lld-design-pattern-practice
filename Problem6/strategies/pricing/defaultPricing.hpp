/**
 * Concrete Default Pricing 
 */
#ifndef DEFAULT_CONCRETE_PRICING_STRATEGY_HPP
#define DEFAULT_CONCRETE_PRICING_STRATEGY_HPP

#include "IPricing.hpp"
#include "../core/tripMetadata.hpp"

class DefaultPricing : public IPricing {
    public: 
        double calculatePrice(TripMetaData* data) {
            (void) data;
            return 80.0; // base fare charging in default
        }
};

#endif