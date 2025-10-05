#ifndef LIBRARIAN_HPP
#define LIBRARIAN_HPP

#include "../books/Inventory.hpp"
#include "User.hpp"
using namespace std;

class Librarian : public User
{
    Inventory *inventory;

public:
    Librarian(const string &userId, const string &name, const string &email,const string &password) : User(userId, name, email, password) {
        inventory = Inventory::getInstance();
    };

    // addBooks
    void addBook(Book* book) {
        inventory->addBooks(book);
        cout << "Librarian " << name << " added book: " << book->getTitle() << endl;
    }

    // removeBooks
    void removeBook(const string& bookId) {
        inventory->removeBooks(bookId);
        cout << "Librarian " << name << " remove book: "  << endl;
    }

    // manageInventory
    void manageInventory() {
        cout << "Librarian " << name << " is managing inventory: " << endl;
        inventory->listAllBooks();
    }
};

#endif