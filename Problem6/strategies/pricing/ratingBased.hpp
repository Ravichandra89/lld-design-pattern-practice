/**
 * RatingBased - Pricing Strategy
 *  - calculated based on the rider and driver rating
 *  
 */
#ifndef RATING_BASED_CONCRETE_STRATEGY_HPP
#define RATING_BASED_CONCRETE_STRATEGY_HPP

#include "IPricing.hpp"

// CalculateRating method
inline double ratingFactor(utils::RATING r) {
    return 1.0 + (static_cast<int>(r) - 3) * 0.05;
}

class RatingBasedPricing : public IPricing {
    public: 
        double calculatePrice(TripMetaData* data) {
            double base = 80.0;
            double factor = ratingFactor(data->getRiderRating()) * ratingFactor(data->getDriverRating());
            return base * factor;
        }
};

#endif