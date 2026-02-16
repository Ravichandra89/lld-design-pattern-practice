/**
 * Combined cart and checkout service header file.
 * Methods : addProductToCart, removeProductFromCart, CalculateTotalPrice, checkout
 */

#ifndef CART_CHECKOUT_HPP
#define CART_CHECKOUT_HPP

#include "../payment/Payment.hpp"
#include "../inventory/Inventory.hpp"
#include "../tax/TaxStrategy.hpp"
#include "../entity/Entities.hpp"
#include "../payment/PaymentFactory.hpp"

using namespace std;

class CartCheckoutService {
        vector<Product> cart;
        Inventory* inventory;
        unique_ptr<TaxStrategy> taxStrategy;

    public: 
        // Constructor
        CartCheckoutService(unique_ptr<TaxStrategy> tax) : inventory(Inventory::getInstance()), taxStrategy(move(tax)) {};
        
        // Add Product to cart
        void addProductToCart(const string& productId, const string& name, double price, int quantity) {
            cout << "Adding product to cart: " << name << " (ID: " << productId << ", Price: " << price << ", Quantity: " << quantity << ")" << endl;

            if (inventory->AvailableQuantity(productId) >= quantity) {
                cart.push_back({productId, name, price});
                inventory->reserveItem(productId, quantity);
                cout << "Product added to cart successfully." << endl;
            }

            cout << "Insufficient stock for product: " << name << endl;
        }

        void removeProductFromCart(const string& productId) {
            cout << "Removing product from Cart: " << productId << endl;

            // Find the product in the cart
            auto it = remove_if(cart.begin(), cart.end(), [&](const Product& p) {
                return p.productId == productId; // match productId's
            });

            if(it != cart.end()) {
                cout << "Product found in cart. Removed successfully." << endl;
                cart.erase(it, cart.end());
            }
            else {
                cout << "Product not found in Cart." << endl;
            }
        }

        double calculateTotalPrice() const {
            double subTotal = 0.0;
            for (const auto & item : cart) {
                // price * quantity
                subTotal = item.price * item.quantity;
            }

            double total = subTotal + taxStrategy->calculateTax(subTotal);
            return total;
        }

        bool checkout(const string& paymentType) {
            // when cart become empty
            if (cart.empty()) {
                cout << "Cart is empty. Cann't proceed to checkout." << endl;
                return false;
            }

            // Reserve Inventory for each product in the cart
            for (const auto & item : cart) {
                if (!inventory->reserveItem(item.productId, item.quantity)) {
                    cout << "Insufficient stock for product: " << item.name << ". Cannot proceed to checkout." << endl;
                    return false;
                }
            }

            // totalAmount calculation
            double totalAmount = calculateTotalPrice();
            cout << "Total amount to be paid: " << totalAmount << endl;

            // Create payment factory instance according to payment type
            unique_ptr<PaymentKaro> paymentMethod = PaymentFactory::createPayment(paymentType);

            if(!paymentMethod->pay(totalAmount)) {
                cout << "Payment failed. Cannot proceed with order confirmation." << endl;
                
                // Release the reserved item in inventory
                for (const auto & item : cart) {
                    inventory->releaseReservedItem(item.productId, item.quantity);
                    cout << "Reserved item released from inventory: " << item.productId << endl;
                }
                return false;
            }
            
            // Make payment
            paymentMethod->pay(totalAmount);
            cout << "Payment successful. Proceeding with order confirmation. " << endl;
            return true;
        }

};

#endif