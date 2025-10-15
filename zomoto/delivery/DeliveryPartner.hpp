#ifndef DELIVERY_PARTNER_HPP
#define DELIVERY_PARTNER_HPP

#include <string>
#include "Interface.hpp"
#include "../utils/Enum.hpp"
#include <iostream>
using namespace std;

class DeliveryPartner : public IPartner {
    public: 
        DeliveryPartner(const string &pName, Rating pRating) : IPartner(pName, pRating) {}

        void performKyc() override {
            // Implement KYC process here
            cout << "Performing KYC for Delivery Partner: " << name << endl;
        }

        // TODO: Make first Delivery MetaData
};

#endif