/**
 * ResturantManager
 * 
 * - resturantManagerInstance : ResturantManager*
- mutex mtx
- resturantMaps : unordered_map<string name, resturant: Resturant*>

 * 
 * - ResturantManager()
+ getResturantManagerInstance(): ResturantManager*
+ getResturant(string name) : Resturant*
+ addResturant(string name, Resturant* resturant)
 */

#ifndef RESTURANT_MANAGER_HPP
#define RESTURANT_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <mutex>
#include "Resturant.hpp"
using namespace std;

// Applying singleton + Double locking
class ResturantManager {
        static ResturantManager* resturantManagerInstance;
        static mutex mtx;

        unordered_map<string, Resturant*> resturants;

        // private constructor
        ResturantManager () {
            cout << "ResturantManager instance created." << endl;
        }

        // Preventing from copy and assignment
        ResturantManager(const ResturantManager&) = delete;
        ResturantManager& operator=(const ResturantManager&) = delete;

    public: 
        // GetResturantManager Instance
        static ResturantManager* getResturantManagerInstance() {
            if (!resturantManagerInstance) {
                lock_guard<mutex> lock(mtx);
                if (!resturantManagerInstance) {
                    // Create instance
                    resturantManagerInstance = new ResturantManager();
                }
            }
        }

        // fetch and return resturants by name MultiThread safe
        Resturant* getResturant(const string& name) {
            lock_guard<mutex> lock(mtx);
            auto it = resturants.find(name);
            if (it != resturants.end()) {
                return it->second;
            }
            cout << "Resturant with name " << name << " not found." << endl;
            return nullptr; 
        }

        // adding resturants
        void addResturant(const string& name, Resturant* resturant) {
            lock_guard<mutex> lock(mtx);
            if (resturants.find(name) == resturants.end()) {
                cout << "Adding resturant: " << name << endl;
                resturants[name] = resturant;
            } else {
                cout << "Resturant with name " << name << " already exists." << endl;
            }
        }

        // DisplayAll Resturants
        void displayAllResturants() {
            cout << "Displaying all resturants:" << endl;
            for (const auto & it : resturants) {
                cout << "------------------------" << endl;
                it.second->display(); // displaying resturants details
            }
        }

};

// Initialize static members
ResturantManager* ResturantManager::resturantManagerInstance = nullptr;
mutex ResturantManager::mtx;

#endif