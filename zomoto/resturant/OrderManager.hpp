/**
 * OrderManager
 * 
 * - orderManagerInstance: OrderManager
 * - mutex mtx
 * - orderMap: map<string, Order*>
 * - foodMgr: FoodManager*
 * - deliveryMgr: DeliveryManager*
 * 
 * - OrderManager()
 * - manageDelivery(string pOrderId, Order* pOrder)
 * - manageFood(string pOrderId, Order* pOrder)
 * + getOrderManagerInstance() : OrderManager
 * + CreateOrder(string pOrderId, Order* pOrder)
 * + getOrder(string pOrderId) : Order*
 */

#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP

#include <string>
#include <map>
#include <mutex>

#include "FoodManager.hpp"
#include "Order.hpp"

using namespace std;

// forward declaration
class DeliveryManager;

class OrderManager {
        static OrderManager* orderManagerInstance;
        static mutex mtx;

        // map of storage
        map<string, Order*> orders;
        FoodManager* foodMgr;
        DeliveryManager* deliveryMgr;

        OrderManager() {
            cout << "OrderManager instance created." << endl;
            foodMgr = FoodManager::getFoodManagerInstance();
            // deliveryMgr = DeliveryManager::getDeliveryManagerInstance();
        }

        // preventing copy and assignment
        OrderManager(const OrderManager&) = delete;
        OrderManager& operator=(const OrderManager&) = delete;
         
        atomic<int> orderCounter{1000};
        string generateOrderId() {
            return "ORD-" + to_string(orderCounter++);
        }

        // manage food
        void manageFood(string pOrderId, Order* pOrder) {
            if (!foodMgr) {
                cout << "FoodManager instance not available." << endl;
                return;
            }
            // prepare food
            cout << "Delegating food preparation to FoodManager for order: " << pOrderId << endl;

            // Prepare dish
            const string& resturantName = pOrder->getRestaurantId();
            unordered_map<Dish*, int> dishes = pOrder->getOrderedDishes();

            bool foodPrepared = foodMgr->prepareFood(pOrderId, resturantName, dishes);

            if (!foodPrepared) {
                cout << "Food preparation failed for order: " << pOrderId << endl;
                pOrder->updateOrderStatus("FOOD_PREPARATION_FAILED");
                return;
            } 
            pOrder->updateOrderStatus("FOOD_PREPARED");
            cout << "Food prepared for order: " << pOrderId << endl;
        }

        // TODO: manage Delivery 

    public: 
        static OrderManager* getOrderManagerInstance() {
            if (!orderManagerInstance) {
                lock_guard<mutex> lock(mtx);
                if (!orderManagerInstance) {
                    orderManagerInstance = new OrderManager();
                }
            }  
            return orderManagerInstance;
        }

        // createOrder - have to generate orderId not taking as input
        Order* createOrder(const string& pResturantName, const string& customerName, unordered_map<Dish*, int> & dishes) {
            string pOrderId = generateOrderId();
            Order* newOrder = new Order(pOrderId, pResturantName, customerName);

            if (!newOrder) {
                cout << "Failed to create order instance. " << endl;
                return nullptr;
            }

            // set dishes
            newOrder->setOrderedDishes(dishes);

            // store in ap
            orders[pOrderId] = newOrder;
            cout << "Order created with ID: " << pOrderId << endl;

            // manage food and Delivery
            manageFood(pOrderId, newOrder);

            // TODO: manage Delivery call

            newOrder->updateOrderStatus("DELIVERED");

            // pring order details
            newOrder->displayOrderInfo();
            return newOrder;
        }

        // getOrder by pOrderId
        Order* getOrder(const string& pOrderId) {
            // find order for given id
            auto it = orders.find(pOrderId);
            if (it != orders.end()) {
                return it->second;
            }

            cout << "Order with ID " << pOrderId << " not found. " << endl;
            return nullptr;
        }

        // cancelOrder - TODO:
        bool cancelOrder(const string& pOrderId) {
            // find order for given I'd
            auto it = orders.find(pOrderId);
            if (it == orders.end()) {
                cout << "Order with ID " << pOrderId << " not found. " << endl;
                return false; 
            }

            Order* order = it->second;
            
            if (!order) {
                cout << "Order instance is null for ID " << pOrderId << endl;
                return false;
            }

            // updating status
            order->updateOrderStatus("CANCELLED");
            cout << "Order with ID " << pOrderId << " has been cancelled. " << endl;
            return true;
        }
};

#endif