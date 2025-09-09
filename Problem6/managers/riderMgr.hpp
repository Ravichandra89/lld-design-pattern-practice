#ifndef RIDER_MANAGER_HPP
#define RIDER_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <mutex>
#include <memory>

#include "../core/rider.hpp"
#include "../utils/utils.hpp"
using namespace std;

class RideManager {
    // Properties 
        unordered_map<string, shared_ptr<Rider>> store_;
        static mutex mtx;
        static RideManager* instance;

        RideManager() = default;

    public: 
        // Copy Constructor
        RideManager(const RideManager& ) = delete;
        RideManager& operator = (const RideManager& ) = delete;

        static RideManager& getRideInstance() {
            if (!instance) {
                lock_guard<mutex> lock(mtx);
                if (!instance) {
                    instance = new RideManager();
                }
            }
            return *instance;
        }

        void addRider(const string& name, utils::RATING r) {
            lock_guard<mutex> lock(mtx);
            store_[name] = make_shared<Rider>(name, r);
        }

        shared_ptr<Rider> getRider(const string& name) {
            // search their name
            lock_guard<mutex> lock(mtx);
            auto it = store_.find(name);
            return it == store_.end() ? nullptr : it->second;
        }
};

#endif