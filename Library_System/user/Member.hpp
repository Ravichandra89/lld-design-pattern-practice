#ifndef MEMBER_HPP
#define MEMBER_HPP

#include "User.hpp"
#include "../books/Borrowing.hpp"
#include "../books/Book.hpp"
#include <vector>
#include <mutex>
#include <iostream>
using namespace std;

class Member : public User
{
    vector<Borrowing *> borrowHistory;
    static mutex mtx;

public:
    // Constructor
    Member(const string &userId, const string &name, const string &email, const string &password) : User(userId, name, email, password) {};

    void borrowBook(Book *book)
    {
        if (!book)
            return;
        if (book->isAvailable())
        {
            lock_guard<mutex> lock(mtx);
            if (book->isAvailable())
            {
                book->setAvailablity(false);
                borrowHistory.push_back(new Borrowing(book->getId(), userId));
                cout << name << " borrowed: " << book->getTitle() << endl;
                return;
            }
        }

        cout << "Book not available " << endl;
    }

    // ReturnBook method
    void returnBook(Book *book)
    {
        if (!book)
            return;

        lock_guard<mutex> lock(mtx);
        book->setAvailablity(true);

        // Remove from the borrowingHistory
        for (auto b : borrowHistory)
        {
            if (b->getId() == book->getId() && !b->isReturned())
            {
                b->markReturned();
                cout << name << " returned : " << book->getTitle() << endl;
                return;
            }
        }
    }

    // viewBorrowBooks
    void viewBorrowBooks()
    {
        lock_guard<mutex> lock(mtx);
        for (auto it : borrowHistory)
        {
            cout << "Borrowed book ID: " << it->getId()
                 << (it->isReturned() ? " [Returned]" : " [Not Returned]") << endl;
        }
    }
};

// Static Variable initilization
mutex Member::mtx;

#endif