#ifndef EMAIL_DELIVERY_HPP
#define EMAIL_DELIVERY_HPP

#include "Interface.hpp"
#include <iostream>
using namespace std;

class EmailDelivery : public IDelivery {
    public: 
        void deliver(const string& mediaPath) override {
            cout << "Delivering via Email to: " << mediaPath << endl;
        }
};

#endif