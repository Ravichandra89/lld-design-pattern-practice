#ifndef SMSNOTIFICATION_H
#define SMSNOTIFICATION_H

#include "Notification.hpp"
#include <iostream>

class SMSNotification : public Notification {
public:
    void send(const string& message, const string& recipient) override {
        cout << "📱 SMS sent to " << recipient << ": " << message << endl;
    }
};

#endif
