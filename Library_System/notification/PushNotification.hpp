#ifndef PUSHNOTIFICATION_H
#define PUSHNOTIFICATION_H

#include "Notification.hpp"
#include <iostream>

class PushNotification : public Notification {
public:
    void send(const string& message, const string& recipient) override {
        cout << "🔔 Push Notification to " << recipient << ": " << message << endl;
    }
};

#endif
