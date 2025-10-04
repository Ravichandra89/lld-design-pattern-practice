#ifndef EMAILNOTIFICATION_H
#define EMAILNOTIFICATION_H

#include "Notification.hpp"
#include <iostream>

class EmailNotification : public Notification {
public:
    void send(const string& message, const string& recipient) override {
        cout << "📧 Email sent to " << recipient << ": " << message << endl;
    }
};

#endif
