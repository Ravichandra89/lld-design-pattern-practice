#ifndef CORE_DRIVER_HPP
#define CORE_DRIVER_HPP

#include <string>
#include "../utils/utils.hpp"

class Driver {
        string driver_name;
        utils::RATING rating;
        bool availability = true;

    public: 
        // constructor 
        Driver(const string& name, utils::RATING r = utils::RATING::THREE) : driver_name(name), rating(r) {};

        utils::RATING getDriverRating() const {
            return rating;
        }

        bool isAvailable() const{
            return availability;
        }

        bool updateAvailability(bool flag) {
            availability = flag;
        }

        string getDriverName() const {
            return driver_name;
        }
};

#endif