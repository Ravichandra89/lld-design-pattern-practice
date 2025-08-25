/**
 * Data Modeling
 */
#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <vector>
#include <string>
#include <memory>
#include <chrono>

// Timestamp defining using chrono
using Timestamp = chrono::time_point<chrono::system_clock>;

using namespace std;

struct MenuItem {
    string id;
    string name;
    string description;
    double price = 0.0;
    string category_id;
    bool is_available = true;
    int available_qty = -1;
    int prep_time_minutes = 0;
    Timestamp created_at;
};

struct customer {
    string id;
    string name;
    string email;
    string phone;
};

// Define OrderItem  - Food as item in an order
struct OrderItem {
    string id;
    string order_id;
    string menu_item_id;
    int quantity = 1;
    double unit_price = 0.0;
    string status; // PENDING | PREPARING | READY | SERVED
};

struct Order {
    string id;
    string customer_id;
    Timestamp created_at;
    string status;
    double total_amount = 0.0;
    string payment_status;
    string payment_method;
    string idempotency_key; // For ensuring idempotent operations Like : Payment does not get processed multiple times
    vector<OrderItem> items;
};

struct Inventory {
    string id;
    string menu_item_id;
    int available_qty = 0;
    int reserved_qty = 0;
    Timestamp updated_at;
};

struct NotificationLog {
    string id;
    string order_id;
    string event_type;
    string payload;
    Timestamp created_at;
    string status; // SENT | FAILED | PENDING
};



#endif