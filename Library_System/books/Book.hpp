#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using namespace std;

class Book
{
    string id;
    string title;
    string author;
    string isbn;
    bool available;

public:
    // constructore
    Book(const string &id, const string &title, const string &author, const string &isbn) : id(id), title(title), author(author), isbn(isbn) {};

    // Getters
    string getId() const
    {
        return id;
    }
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getIsbn() const
    {
        return isbn;
    }

    bool isAvailable() const
    {
        return available;
    };
    void setAvailablity(bool val)
    {
        available = val;
    }
};

#endif