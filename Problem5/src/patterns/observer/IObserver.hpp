/**
 * Notification System Observer Pattern Interface
 */
#ifndef I_NOTIFICATIOIN_HPP
#define I_NOTIFICATIION_HPP

#include <string>
using namespace std;

class IObserver {
    public: 
        virtual ~IObserver() = default;
        virtual void onNotify(const string& orderId, const string& message) = 0;
};

#endif