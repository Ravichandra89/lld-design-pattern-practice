/**
 * Inventory Manager is there  - SingleTon Pattern 
 * AddItemStock()
 * reserveItem()
 * 
 */
#ifndef INVENTORY_INTERFACE_HPP
#define INVENTORY_INTERFACE_HPP

#include <string>
#include <vector>
#include <mutex>
#include <unordered_map>

using namespace std;

struct InventoryStructure {
    int availableQuantity = 0;
    int reservedQuantity = 0;
};

class Inventory {
    // Constructor in Private Accessifer
    Inventory() = default;

    static Inventory* InvInstance;
    static mutex mtx;
    unordered_map<string, InventoryStructure> inventoryMap;

    public: 
        // Copy Constructor Deletion
        Inventory(const Inventory&) = delete;
        Inventory& operator=(const Inventory&) = delete;

        // Inventory Methods
        static Inventory* getInstance() {
            //  applying Double-Checked Locking
            lock_guard<mutex> lock(mtx);
            if (!InvInstance) {
                // Creating a new instance
                InvInstance = new Inventory();
            }
            return InvInstance;
        }

        void addItemStock(const string& productId, int quantity) {
            inventoryMap[productId].availableQuantity += quantity;
        }

        // Check if the item is Reserved or not
        // Check the item quantity available or not - With Double Locking
        
        bool reserveItem(const string& productId, int quantity) {
            lock_guard<mutex> lock(mtx);
            auto it = inventoryMap[productId];
            if (it.availableQuantity >= quantity) {
                // Reserve the item and update the available quantity
                it.availableQuantity -= quantity;
                it.reservedQuantity += quantity;
                inventoryMap[productId] = it;
                return true;
            }
            return false; 
        }

        bool releaseReservedItem(const string& productId, int quantity) {
            auto item = inventoryMap[productId];
            item.availableQuantity += quantity;

            if (item.reservedQuantity >= quantity) {
                item.reservedQuantity -= quantity;
                inventoryMap[productId] = item;
                return true;
            }

            return false;
        }

        int AvailableQuantity(const string& productId) {
            auto item = inventoryMap[productId];

            if(item.availableQuantity > 0) {
                return item.availableQuantity;
            }

            // Empty Inventory for "ProductId"
            return 0;
        }
};

// Static member Initialization
Inventory* Inventory::InvInstance = nullptr;
mutex Inventory::mtx;

#endif