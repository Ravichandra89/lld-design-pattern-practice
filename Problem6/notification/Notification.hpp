/**
 * Centeral Notification service this is...
 */

#ifndef NOTIFICATION_SERVICE_HPP
#define NOTIFICATION_SERVICE_HPP

#include "INotification.hpp"
#include <memory>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

class Notification {
        mutex mtx;
        // list of observers
        vector<shared_ptr<INotification>> observers_;

    public:     
        void attach(shared_ptr<INotification> obv) {
            lock_guard<mutex> lock(mtx);
            observers_.push_back(obv);
        }

        void detach(const string & channel) {
            lock_guard<mutex> lock(mtx);
            observers_.erase(remove_if(observers_.begin(), observers_.end(),
            [&](const std::shared_ptr<INotification>& o){ return o->getChannel() == channel; }),
            observers_.end());
        }
        
        void notifyAll(const string& recepient, const string& title, const string& body) {
            vector<shared_ptr<INotification>> copy;
            {
                lock_guard<mutex> lock(mtx);
                copy = observers_;
            }

            for (auto & it : copy) {
                it->sendNotification(recepient, title, body); // sending notification
            }
        }

        void notifyChannel(const string& channel, const string& recepient, const string& title, const string& body) {
            vector<shared_ptr<INotification>> copy;
            {
                lock_guard<mutex> lock(mtx);
                copy = observers_;
            }

            for (auto & it : copy) {
                if (it && it->getChannel() == channel) {
                    it->sendNotification(recepient, title, body);
                }
            }
        }
};

#endif