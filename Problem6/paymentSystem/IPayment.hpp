#ifndef IPAYMENT_HPP
#define IPAYMENT_HPP

#include <string>
using namespace std;

class IPayment {
    public: 
        virtual ~IPayment() = default;
        virtual bool processPayment(double amount, const string& tripId) = 0;
};

#endif