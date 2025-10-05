#ifndef LIBRARY_SYSTEM_HPP
#define LIBRARY_SYSTEM_HPP

#include "../subsystems/borrowingManager.hpp"
#include "../subsystems/inventoryManager.hpp"
#include "../subsystems/notificationManager.hpp"
#include "../subsystems/userManager.hpp"
#include <mutex>

using namespace std;

// Singleton + Mutex Locking
class LibrarySystem
{
    static LibrarySystem *instance;
    static mutex mtx;

    // Instance of subsystems
    userManager user;
    InventoryManager inventory;
    NotificationManager notify;
    BorrowingManager borrow;

    // private constructor
    LibrarySystem() : borrow(&notify) {}

public:
    /**
     * GetInstance Method
     */
    static LibrarySystem *getInstance()
    {
        if (!instance)
        {
            lock_guard<mutex> lock(mtx);
            if (!instance)
            {
                instance = new LibrarySystem();
            }
        }
        return instance;
    }

    // Exposing API's
    void addUser(User *u)
    {
        user.addUser(u);
    }

    User *getUser(const string &id)
    {
        user.getUser(id);
    }

    // Book's
    void addBook(Book *b)
    {
        inventory.addBook(b);
    }

    void removeBook(const string &bookId)
    {
        inventory.removeBook(bookId);
    }

    void listsBooks()
    {
        inventory.listBooks();
    }

    // Notification
    void setNotificationChannel(const string &type)
    {
        notify.setChannel(type);
    }

    // Borrowing book
    void borrowBook(const string &memberId, Book *book)
    {
        borrow.borrowBook(user.getUser(memberId), book);
    }

    // Returning book
    void returnBook(const string &memberId, Book *book)
    {
        borrow.returnBook(user.getUser(memberId), book);
    }
};

LibrarySystem *LibrarySystem::instance = nullptr;
mutex LibrarySystem::mtx;

#endif