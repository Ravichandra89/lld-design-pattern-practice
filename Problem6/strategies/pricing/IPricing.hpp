#ifndef IPRICING_HPP
#define IPRICING_HPP

#include "../core/tripMetadata.hpp"


class IPricing {
    public: 
        virtual ~IPricing() = default;
        virtual double calculatePrice(const TripMetaData* data) = 0;
};

#endif