#ifndef CONCRETE_NOTIFICATION_OBSERVER_SERVICE
#define CONCRETE_NOTIFICATION_OBSERVER_SERVICE

#include "IObserver.hpp"
#include <iostream>
using namespace std;

class notificationService : public IObserver {
    public: 
        void onNotify(const string& orderId, const string& message) override {
            cout << "[Notify] Order" << orderId << ": " << message << endl;
        }
};

#endif