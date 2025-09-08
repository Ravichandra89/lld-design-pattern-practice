#ifndef CONCRETE_PUSH_NOTIFICATION_HPP
#define CONCRETE_PUSH_NOTIFICATION_HPP

#include "INotification.hpp"

class SMS : public INotification {
    public: 
        void sendNotification(const string& recipient, const string& title, const string& body) {
            cout << "[SMS Notification] to=" << recipient << " sub=\"" << title << "\" body=\"" << body << "\"\n";
        };

        string getChannel() const override {
            return "sms_notification";
        }

};

#endif