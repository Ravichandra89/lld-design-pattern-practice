#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>
#include <cmath>
#include <iostream>
using namespace std;

// managing location by langitude and latitude
class Location {   
    double latitude;
    double longitude;
    string address;

public: 
    // Constructor
    Location(double lat, double lon, const string& addr) : latitude(lat), longitude(lon), address(addr) {};

    // Getters
    double getLatitude() const {
        return latitude;
    }
    
    double getLongitude() const {
        return longitude;
    }

    string getAddress() const {
        return address;
    }

    // Setters
    void setLatitude(double lat) {
        latitude = lat;
    }

    void setLongitude(double lon) {
        longitude = lon;
    }

    void setAddress(const string& addr) {
        address = addr;
    }

    // Calculating 
    double distanceTo(const Location& other) const {
        const double radius = 6371.0;
        double lat1 = latitude * M_PI / 180.0;
        double lon1 = longitude * M_PI / 180.0;
        double lat2 = other.latitude * M_PI / 180.0;
        double lon2 = other.longitude * M_PI / 180.0;

        double dlat = lat2 - lat1;
        double dlon = lon2 - lon1;

        double a = sin(dlat / 2) * sin(dlat / 2) +
                   cos(lat1) * cos(lat2) * 
                   sin(dlon / 2) * sin(dlon / 2);

        double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        return radius * c;
    }

    // Display location
    void display() const {
        cout << "Address: " << address << ", Latitude: " << latitude << ", Longitude: " << longitude << endl;
    }
};

#endif