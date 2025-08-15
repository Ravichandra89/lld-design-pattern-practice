#ifndef ECOMMERCE_CART_ENTITIES_HPP
#define ECOMMERCE_CART_ENTITIES_HPP

#include <string>
#include <vector>
#include <memory>

using namespace std;

// Write all the Entities
struct Product
{
    string productId;
    string name;
    double price;
    int quantity = 0;
};

struct InventoryItem
{
    string productId;
    int availableQuantity = 0;
    int reservedQuantity = 0;
};

struct CartInventoryItem
{
    string productId;
    int quantity = 0;

    // Unit_Price
};

enum class OrderStatus
{
    Pending,
    Confirmed,
    Shipped,
    Delivered,
    Cancelled,
    Returned,
    Refunded,
    Failed,
};

struct Cart
{
    string cartId;
    string userId;
    vector<CartInventoryItem> items;
};

struct Money {
    long long amount = 0;
    Money() = default;
    explicit Money(long long a): amount(a) {}
    std::string toString() const {
        long long rupees = amount / 100;
        int paise = amount % 100;
        return std::to_string(rupees) + "." + (paise < 10 ? "0" : "") + std::to_string(paise);
    }
};

struct OrderStructure
{
    string productId;
    int quantity = 0;
    Money unitPrice;
};

struct Order {
    string orderId;
    string userId;
    vector<OrderStructure> items;
    Money totalAmount;
    Money subTotal;
    Money tax;
    OrderStatus status = OrderStatus::Pending;
};

enum class PaymentStatus{
    Pending,
    Completed,
    Failed,
    Refunded,
    Cancelled
};

struct Payment {
    string paymentId;
    string orderId;
    Money amount;
    PaymentStatus status = PaymentStatus::Failed;
    string paymentMethod;

};


#endif