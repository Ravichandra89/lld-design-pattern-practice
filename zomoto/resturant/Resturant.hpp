/**
 * Implementing Resturant class
 */
#ifndef RESTURANT_HPP
#define RESTURANT_HPP

#include <string>
#include <vector>
#include "utils/Location.hpp"
#include "resturant/Dish.hpp"
#include "utils/Enum.hpp"
#include "unordered_map"

using namespace std;

// Forward Menu and Dish classes declaration
class Menu;

class Resturant {
    string name;
    string description;
    Location location;
    bool isAvailable;
    Location* location;
    Menu* menu;

public: 
    Resturant(const string& name, const string& description, const Location& loc) : name(name), description(description), location(loc), isAvailable(true), menu(nullptr) {};

    // setters
    void setMenu(Menu* m) {
        menu = m;
    }

    void setAvailability(bool available) {
        isAvailable = available;
    }

    // getters
    string getName() const {
        return name;
    }
    string getDescription() const {
        return description;
    }
    Location getLocation() const {
        return location;
    }
    bool getAvailability() const {
        return isAvailable;
    }

    // Prepare food method
    bool prepareFood(const string& pOrderId, const unordered_map<Dish*, int> & dishes) {
        if (!isAvailable && !menu) {
            cout << "Resturant is not available or menu is not set." << endl;
            return false;
        }

        // Started processing order
        cout << "Order " << pOrderId << " is being prepared at " << name << endl;

        for (const auto & it : dishes) {
            Dish* dish = it.first;
            int quantity = it.second;

            if (!dish) {
                cout << "Invalid dish in the order." << endl;
                return false;
            }

            cout << "  - " << dish->getName() << " x " << quantity << " ...done!" << endl;
        }

        cout << "Order " << pOrderId << " has been prepared successfully!" << endl;
        return true;
    }

    // Display resturant details
    void display() const {
        cout << "Resturant Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
        location.display();
        if (menu) {
            cout << "Menu is set." << endl;
        } else {
            cout << "Menu is not set." << endl;
        }
    }
};

#endif