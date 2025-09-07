#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
using namespace std;

// Grouping identifiers (functions, classes, variables and etc..)
namespace utils { 
   
    // Define the Rating
    enum class RATING : int {
        ONE=1,
        TWO,
        THREE,
        FOUR,
        FIVE,
    };

    enum class TRIP_STATUS {
        REQUESTED, 
        MATCHED, 
        ONGOING, 
        COMPLETED, 
        CANCELLED
    };

    struct Location {
        double lat{0.0}, lon{0.0};
        Location() = default;
        Location(double la, double lo) : lat(la), lon(lo) {};
    };

    // inline statusToString() - Make header method under the One definition Rule
    inline string statusToString(TRIP_STATUS s) {
        switch(s) {
            case TRIP_STATUS::REQUESTED : return "REQUESTED";
            case TRIP_STATUS::CANCELLED : return "CANCELLED";
            case TRIP_STATUS::COMPLETED : return "COMPLETED";
            case TRIP_STATUS::MATCHED : return "MATCHED";
            case TRIP_STATUS::ONGOING: return "ONGOING";
        }
        return "UNKOWN";
    }
}

#endif