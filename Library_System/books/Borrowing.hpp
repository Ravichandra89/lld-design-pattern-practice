#ifndef BORROWING_HPP
#define BORROWING_HPP

#include "Book.hpp"

class Borrowing
{
    string bookId;
    string memberId;
    time_t borrowDate;
    time_t returnDate;
    bool returned;

public:
    // methods- Constructor
    Borrowing(const string &bookId, const string &memberId) : bookId(bookId), memberId(memberId)
    {
        borrowDate = time(nullptr);
        returnDate = 0;
    }

    // markReturned - the book
    void markReturned()
    {
        returned = true;
        returnDate = time(nullptr);
    }

    // Defining the Getters
    bool isReturned() const
    {
        return returned;
    }

    string getId() const
    {
        return bookId;
    }

    string getMemberId() const
    {
        return memberId;
    }

    time_t getBorrowedDate() const
    {
        return borrowDate;
    }

    time_t getRetunredDate() const
    {
        return returnDate;
    }
};

#endif