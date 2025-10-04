#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include <string>
using namespace std;

class Notification {
    public: 
        virtual ~Notification() {};
        virtual void send(const string& message, const string& receipent) = 0;
};

#endif