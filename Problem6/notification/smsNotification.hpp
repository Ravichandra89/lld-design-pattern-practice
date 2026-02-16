#ifndef CONCRETE_EMAIL_NOTIFICATION_HPP
#define CONCRETE_EMAIL_NOTIFICATION_HPP

#include "INotification.hpp"

class Email : public INotification {
    public: 
        void sendNotification(const string& recipient, const string& title, const string& body) {
            cout << "[Email] to=" << recipient << " sub=\"" << title << "\" body=\"" << body << "\"\n";
        };

};

#endif