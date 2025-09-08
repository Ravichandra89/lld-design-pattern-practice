/**
 * matchDriver() : shared_ptr<Driver> 
 */
#ifndef IDRIVER_HPP
#define IDRIVER_HPP

#include <memory>
using namespace std;

// Forward Declaration
class TripMetaData;
class Driver;

class IDriver {
    public: 
        virtual ~IDriver() = default;
        virtual shared_ptr<Driver> matchDriver(TripMetaData* data) = 0;
};

#endif