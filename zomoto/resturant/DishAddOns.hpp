#ifndef DISHADDONS_HPP
#define DISHADDONS_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// DishAddOns Class 
class DishAddOns {
        string name;
        double price;
        vector<string> images;
    
    public:
        DishAddOns(const string& name, double price, const vector<string>& images) 
            : name(name), price(price), images(images) {}

        // setters
        void setName(const string& n) {
            name = n;
        }
    
        void setPrice(double p) {
            price = p;
        }
        void setImages(const vector<string>& imgs) {
            images = imgs;
        }

        // getters
        string getName() const {
            return name;
        }

        double getPrice() const {
            return price;
        }

        // images getter
        vector<string> getImages() const {
            return images;
        }

        // displaying details of addOns
        void display() const {
            cout << "AddOn Name: " << name << endl;
            cout << "Price: $" << price << endl;
            cout << "Images: ";
            for (const auto& img : images) {
                cout << img << " ";
            }
            cout << endl;
        }
};

#endif