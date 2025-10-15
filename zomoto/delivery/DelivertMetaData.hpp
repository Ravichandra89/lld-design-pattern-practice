#ifndef DELIVERY_META_DATA_HPP
#define DELIVERY_META_DATA_HPP

#include <string>
#include <iostream>
#include "../utils/Location.hpp"
using namespace std;

class DeliveryMetaData {
        Location* userLoc;
        Location* resturantLoc;
        string orderId;

    public: 
        DeliveryMetaData(Location* pUserLoc, Location* pResturantLoc, const string& pOrderId) : userLoc(pUserLoc), resturantLoc(pResturantLoc), orderId(pOrderId) {};

        // Getters
        Location* getUserLocation() const {
            return userLoc;
        }

        Location* getResturantLocation() const {
            return resturantLoc;
        }

        string getOrderId() const {
            return orderId;
        }

        // calculate distance
        double calculateDistance() const {
            if (!userLoc || !resturantLoc) {
                cout << "Invalid locations for distance calculation. " << endl;
                return -1.0;
            }
            return userLoc->distanceTo(*resturantLoc);
        }

        // Display metadata
        void display() const {
            cout << "Order ID: " << orderId << endl;
            if (userLoc) {
                cout << "User Location: ";
                userLoc->display();
            } else {
                cout << "User Location: Not available" << endl;
            }

            if (resturantLoc) {
                cout << "Resturant Location: ";
                resturantLoc->display();
            } else {
                cout << "Resturant Location: Not available" << endl;
            }

            double distance = calculateDistance();
            if (distance >= 0.0) {
                cout << "Distance between User and Resturant: " << distance << " km" << endl;
            } else {
                cout << "Distance calculation failed." << endl;
            }
        }
};

#endif