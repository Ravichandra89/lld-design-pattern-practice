#ifndef INEVNTORY_HPP
#define INEVNTORY_HPP

#include "Book.hpp"
#include <vector>
#include <iostream>
#include <mutex>

using namespace std;

class Inventory
{
    vector<Book *> books;

    // singleton inventory instance
    static Inventory *instance;
    static mutex mtx;

    // Constructor Inventory - Private
    Inventory() {};

public:
    Inventory(const Inventory &) = delete;
    Inventory &operator=(const Inventory &) = delete;

    // GetInstance
    static Inventory *getInstance()
    {
        if (instance == nullptr)
        {
            // apply the lock
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                // create new instance
                instance = new Inventory();
            }
        }

        return instance;
    }

    // add Books
    void addBooks(Book *book)
    {
        books.push_back(book);
    }

    // remove Books - find book by id and matching bookId delete that book
    void removeBooks(const string &bookId)
    {
        books.erase(remove_if(books.begin(), books.end(),
                              [&](Book *b)
                              { return b->getId() == bookId; }),
                    books.end());
    }

    // search book by *id
    Book *searchBookById(const string &bookId)
    {
        for (auto &it : books)
        {
            if (it->getId() == bookId)
                return it;
        }
        return nullptr;
    }

    // search book by Author
    Book *searchBookByAuthor(const string &authorName)
    {
        for (auto &it : books)
        {
            if (it->getAuthor() == authorName)
                return it;
        }
        return nullptr;
    }

    // Listing all books
    void listAllBooks()
    {
        for (auto b : books)
        {
            cout << b->getTitle() << " by " << b->getAuthor()
                 << (b->isAvailable() ? " [Available]" : " [Borrowed]") << endl;
        }
    }
};

Inventory *Inventory::instance = nullptr;
mutex Inventory::mtx;

#endif