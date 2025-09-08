/** 
 * Select the driver based on the least time
 */
#ifndef LEAST_TIME_BASED_DRIVER_HPP
#define LEAST_TIME_BASED_DRIVER_HPP

#include "IDriver.hpp"
#include <memory>

class LeastTimeBased : public IDriver {
        shared_ptr<Driver> candidate_;
    public: 
        LeastTimeBased(shared_ptr<Driver> can) : candidate_(can) {};
        
        shared_ptr<Driver> matchDriver(TripMetaData* data) override {
            (void)data;
            return candidate_;
        }
};

#endif