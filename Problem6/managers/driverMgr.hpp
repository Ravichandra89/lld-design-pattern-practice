#ifndef DRIVER_MANAGER_HPP
#define DRIVER_MANAGER_HPP

#include <unordered_map>
#include <mutex>

#include "../core/driver.hpp"
#include "../utils/utils.hpp"

using namespace std;

class DriverManager {
        static mutex mtx;
        unordered_map<string, shared_ptr<Driver>> store_;
        static DriverManager* instance;

        DriverManager() = default;

    public: 
        static DriverManager& getDriverInstance() {
            if (!instance) {
                lock_guard<mutex> lock(mtx);
                if (!instance) {
                    instance = new DriverManager();
                }
            }
            return *instance;
        }

        void addDriver(const string& name, utils::RATING r) {
            lock_guard<mutex> lock(mtx);
            store_[name] = make_shared<Driver> (name, r);
        }

        shared_ptr<Driver> getDriver(const string& name) {
            lock_guard<mutex> lock(mtx);
            auto it = store_.find(name);
            return it == store_.end() ? nullptr : it->second;
        }
};

#endif