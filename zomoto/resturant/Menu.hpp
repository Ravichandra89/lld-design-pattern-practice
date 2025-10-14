#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include "Dish.hpp"
using namespace std;

class Menu {
    string name;
    vector<Dish> dishes; 

public:
    Menu(const string& name) : name(name) {}

    // setters
    void setName(const string& name) {
        this->name = name;
    }

    // add dish by value (composition)
    void addDish(const Dish& dish) {
        dishes.push_back(dish);
    }

    const vector<Dish>& getDishes() const {
        return dishes;
    }

    void display() const {
        cout << "Menu: " << name << endl;
        for (const auto& dish : dishes) {
            dish.display();
            cout << "-------------------" << endl;
        }
    }
};

#endif
