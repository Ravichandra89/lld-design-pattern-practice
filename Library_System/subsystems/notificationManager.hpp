#ifndef NOTIFICATION_MANAGER_HPP
#define NOTIFICATION_MANAGER_HPP

#include "../notification/Notification.hpp"
#include "../notification/Factory.hpp"
#include <iostream>
using namespace std;

class NotificationManager {
        Notification* notifier = nullptr;
    public:
        void setChannel(const string& type) {
            if (notifier) delete notifier;
            notifier = NotificationFactory::createNotification(type);
        }

        void notify(const string& msg, const string& recipient) {
            if (notifier) notifier->send(msg, recipient);
            else cout << "⚠️ No notification channel set!\n";
        }
};

#endif