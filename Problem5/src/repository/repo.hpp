/**
 * IdGenerator()
 * MenuRepository:
 *  - add()
 *  - get()
 *  - all()
 *  - decrementIfAvailable()
 *
 * OrderRepository:
 *  - add()
 *  - get()
 *  - findByIdempotency()
 *
 * InventoryRepository:
 *  - set()
 *  - getByItem()
 *  - reserve()
 *  - release()
 */

#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include "../entities/Entities.hpp"
#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>
#include <mutex>
#include <atomic>

using namespace std;

struct IdGenerator {
    static inline atomic<int> counter{1};
    static string next(const string &prefix = "") {
        auto v = counter.fetch_add(1);
        return prefix + std::to_string(v);
    }
};

// MenuRepository 
class MenuRepository {
    unordered_map<string, MenuItem> items;
    mutex mtx;

    public: 
        void add(const MenuItem & item) {
            // Double locking to avoid
            lock_guard<mutex> lock(mtx);
            items[item.id] = item;
        }

        optional<MenuItem> get(const string& id) {
            lock_guard<mutex> lock(mtx);

            // search for the item
            if (items.find(id) == items.end()) {
                return nullopt;
            }
            return items[id];
        }

        // return all items
        vector<MenuItem> all() {
            lock_guard<mutex> lock(mtx);
            vector<MenuItem> result;
            result.reserve(items.size());
            for (const auto & it : items) {
                result.push_back(it.second);
            }
            return result;
        }

        // decrement available quantity if available
        bool decrementIfAvailable(const string& id, int qty) {
            lock_guard<mutex> lock(mtx);
            auto it = items.find(id);
            if (it == items.end()) {
                return false;
            }

            // check availability
            if (!it->second.is_available) {
                return false;
            }
            if (it->second.available_qty != -1 && it->second.available_qty < qty) {
                return false;
            }

            // decrement quantity
            if (it->second.available_qty != -1) {
                it->second.available_qty -= qty;
            }

            return true;
        }
};
#endif