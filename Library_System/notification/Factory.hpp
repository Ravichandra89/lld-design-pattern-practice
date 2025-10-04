#ifndef NOTIFICATIONFACTORY_H
#define NOTIFICATIONFACTORY_H

#include "Notification.hpp"
#include "EmailNotitification.hpp"
#include "PushNotification.hpp"
#include "SmsNotification.hpp"

#include <string>

class NotificationFactory {
public:
    static Notification* createNotification(const string& type) {
        if (type == "email") {
            return new EmailNotification();
        } else if (type == "sms") {
            return new SMSNotification();
        } else if (type == "push") {
            return new PushNotification();
        } else {
            return nullptr;
        }
    }
};

#endif
