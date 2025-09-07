#ifndef CORE_TRIP_METADATA_HPP
#define CORE_TRIP_METADATA_HPP

#include <string>
#include "../utils/utils.hpp"
using namespace std;

class TripMetaData {
        utils::Location srcLoc;
        utils::Location destLoc;
        utils::RATING driver_rating;
        utils::RATING rider_rating;
        
    public: 
        // Costructor
        TripMetaData(const utils::Location& s, const utils::Location& d, utils::RATING riderRate, utils::RATING driverRate) : rider_rating(riderRate), driver_rating(driverRate), srcLoc(s), destLoc(d) {};

        utils::RATING getRiderRating() const {
            return rider_rating;
        }

        utils::RATING getDriverRating() const {
            return driver_rating;
        }

        // get source and destination
        utils::Location getSrcLocation() const {
            return srcLoc;
        }

        utils::Location getDestLocation() const {
            return destLoc;
        }

        utils::RATING setDriverRating(utils::RATING dr) {
            driver_rating = dr;
        }
};

#endif