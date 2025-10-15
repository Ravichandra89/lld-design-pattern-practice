/**
 * FoodManager
 * 
 * - foodManagerInstance: FoodManager
 * - mutex : mtx
 * 
 * - FoodManager()
 * + getFoodManagerInstance(): FoodManager*
 * + prepareFood(string pOrderId, string pResturantId,
 */

#ifndef FOOD_MANAGER_HPP
#define FOOD_MANAGER_HPP

#include <string>
#include <mutex>
#include <unordered_map>
#include <iostream>
#include "Dish.hpp"
#include "ResturantManager.hpp"
using namespace std;

class FoodManager {
        static FoodManager* foodManagerInstance;
        static mutex mtx;

        // private constructor
        FoodManager() {
            cout << "FoodManager instance created." << endl;
        }

        // preventing copy and assignment
        FoodManager(const FoodManager&) = delete;
        FoodManager& operator=(const FoodManager&) = delete;

    public: 
        static FoodManager* getFoodManagerInstance() {
            if (!foodManagerInstance) {
                lock_guard<mutex> lock(mtx);
                if (!foodManagerInstance) {
                    foodManagerInstance = new FoodManager();
                }
            }
        }

        bool prepareFood(const string& pOrderId, const string& resturantName, unordered_map<Dish*, int> & dishes) {
            // get resturantManagerInstance
            ResturantManager* resturantManager = ResturantManager::getResturantManagerInstance();

            if (!resturantManager) {
                cout << "ResturantManager instance not available. " << endl;
                return false;
            }

            // fetch the resturant by 
            Resturant* resturant = resturantManager->getResturant(resturantName);
            if (!resturant) {
                cout << "Resturant with name " << resturantName << " not found. " << endl;
                return false;
            }

            // Prepare the food from fetched resturant
            cout << "Delegating food preparation to resturant: " << resturantName << endl;
            return resturant->prepareFood(pOrderId, dishes);
        }
};

// Initialize static members
FoodManager* FoodManager::foodManagerInstance = nullptr;
mutex FoodManager::mtx;

#endif