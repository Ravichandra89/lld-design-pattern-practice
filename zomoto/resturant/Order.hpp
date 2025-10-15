#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Dish.hpp"

using namespace std;

class Order
{
private:
    string orderId;
    string restaurantId;
    string customerName;
    vector<string> foodItems;                 
    unordered_map<Dish *, int> orderedDishes; 
    string orderStatus;
    double totalAmount;

public:
    // Constructor
    Order(const string &pOrderId, const string &pRestaurantId, const string &pCustomerName)
        : orderId(pOrderId),
          restaurantId(pRestaurantId),
          customerName(pCustomerName),
          orderStatus("CREATED"),
          totalAmount(0.0) {}

    // Disable copy
    Order(const Order &) = delete;
    Order &operator=(const Order &) = delete;

    // Enable move
    Order(Order &&) = default;
    Order &operator=(Order &&) = default;

    // Getters
    string getOrderId() const { return orderId; }
    string getRestaurantId() const { return restaurantId; }
    string getCustomerName() const { return customerName; }
    string getOrderStatus() const { return orderStatus; }
    double getTotalAmount() const { return totalAmount; }

    // ✅ Add food item (string + Dish object)
    void addFoodItem(Dish *dish, int quantity)
    {
        if (dish == nullptr)
            return;

        orderedDishes[dish] = quantity;
        foodItems.push_back(dish->getName());
        totalAmount += dish->getPrice() * quantity;
    }

    // ✅ Get dishes (for FoodManager)
    unordered_map<Dish *, int> &getOrderedDishes()
    {
        return orderedDishes;
    }

    // ✅ Set entire dish map (used when creating order in manager)
    void setOrderedDishes(const unordered_map<Dish *, int> &dishes)
    {
        orderedDishes = dishes;
        foodItems.clear();
        totalAmount = 0.0;

        for (const auto &pair : dishes)
        {
            Dish *dish = pair.first;
            int qty = pair.second;
            if (dish)
            {
                foodItems.push_back(dish->getName());
                totalAmount += dish->getPrice() * qty;
            }
        }
    }

    // ✅ Update order status
    void updateOrderStatus(const string &status)
    {
        orderStatus = status;
    }

    // ✅ Display order info
    void displayOrderInfo() const
    {
        cout << "\n===== ORDER DETAILS =====" << endl;
        cout << "Order ID      : " << orderId << endl;
        cout << "Restaurant ID : " << restaurantId << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Status        : " << orderStatus << endl;
        cout << "Items         : ";
        for (const auto &item : foodItems)
            cout << item << " ";
        cout << "\nTotal Amount  : $" << totalAmount << endl;
        cout << "==========================" << endl;
    }
};

#endif // ORDER_HPP
