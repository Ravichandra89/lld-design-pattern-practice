#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Header Files Required
#include "HeaderFile/services/CartCheckout.hpp"
#include "HeaderFile/entity/Entities.hpp"
#include "HeaderFile/payment/PaymentFactory.hpp"
#include "HeaderFile/payment/Payment.hpp"
#include "HeaderFile/Inventory/Inventory.hpp"
#include "HeaderFile/tax/InrTaxStrategy.hpp"

using namespace std;

int main() {
    // Setup Inventory (Singleton Pattern)
    Inventory* inventory = Inventory::getInstance();
    inventory->addItemStock("P001", 100);
    inventory->addItemStock("P002", 50);
    inventory->addItemStock("P003", 200);
    inventory->addItemStock("P004", 0); 
    inventory->addItemStock("P005", 75);

    // create service with Inr Tax Strategy
    unique_ptr<TaxStrategy> strategy = make_unique<InrTaxStrategy>();
    CartCheckoutService service(move(strategy));

    // Add Products to Cart
    service.addProductToCart("P001", "Product 1", 100.0, 1);
    service.addProductToCart("P002", "Product 2", 200.0, 1);

    // Remove Products from Cart
    service.removeProductFromCart("P001");

    // Checkout with Payment Type UPI
    if (service.checkout("UPI")) {
        cout << "Checkout Successful!" << endl;
    } else {
        cout << "Checkout Failed!" << endl;
    }

    return 0;
} 