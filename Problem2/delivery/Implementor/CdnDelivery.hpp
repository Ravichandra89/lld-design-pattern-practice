#ifndef CDN_DELIVERY_HPP
#define CDN_DELIVERY_HPP

#include "Interface.hpp"
#include <iostream>
using namespace std;

class CdnDelivery : public IDelivery {
    public: 
        void deliver(const string& mediaPath) override {
            cout << "Delivering via CDN to:  " << mediaPath << endl; 
        }
};

#endif