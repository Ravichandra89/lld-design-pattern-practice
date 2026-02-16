#ifndef INOTIFICATION_HPP
#define INOTIFICATION_HPP

#include <string>
#include <iostream>
using namespace std;

class INotification {
    public: 
        virtual ~INotification() = default;
        virtual void sendNotification(const string& recipient, const string& title, const string& body) = 0;
        virtual string getChannel() const = 0;
};

#endif