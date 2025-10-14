#ifndef DISH_HPP
#define DISH_HPP

#include <string>
#include <vector>
#include <iostream>
#include "DishAddOns.hpp"
#include "utils/Enum.hpp"
using namespace std;

class Dish
{
    string name;
    double price;
    vector<string> images;
    DishAddOns addOns; 

public:
    Dish(const string &name, double price, const vector<string> &images,
         const DishAddOns &addOns)
        : name(name), price(price), images(images), addOns(addOns) {}

    // setters
    void setName(const string &n) { name = n; }
    void setPrice(double p) { price = p; }
    void setImages(const vector<string> &imgs) { images = imgs; }
    void setAddOns(const DishAddOns &addOn) { addOns = addOn; }

    // getters
    string getName() const { return name; }
    double getPrice() const { return price; }
    vector<string> getImages() const { return images; }
    DishAddOns getAddOns() const { return addOns; }

    void display() const
    {
        cout << "Dish Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Images: ";
        for (const auto &img : images)
            cout << img << " ";
        cout << endl;
        cout << "Add-Ons: " << endl;
        addOns.display();
    }
};

#endif
