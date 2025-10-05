#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "../books/Inventory.hpp"

class InventoryManager
{
    Inventory *inventory;

public:
    InventoryManager() {
        inventory = Inventory::getInstance();
    }

    // addBook(), removeBook(), listBooks()
    void addBook(Book* book) {
        inventory->addBooks(book);
    }
    void removeBook(const string& bookid) {
        inventory->removeBooks(bookid);
    }
    void listBooks() {
        inventory->listAllBooks();
    }

    // SearchBookId
    Book* searchBookById(const string& bookid) {
        return inventory->searchBookById(bookid);
    }
};
#endif
