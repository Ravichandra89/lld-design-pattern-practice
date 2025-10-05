#include <iostream>
#include "LibrarySystem.hpp"
#include "books/Book.hpp"
#include "user/Member.hpp"
#include "user/Librarian.hpp"

using namespace std;

int main()
{
    cout << "=== Library Management Systemm (LLD + Facade) ===\n\n";
    LibrarySystem *lib = LibrarySystem::getInstance();
    lib->setNotificationChannel("email");

    // Step 3: Create Users (Member and Librarian)
    Member *member1 = new Member("M1", "Ravi", "ravi@mail.com", "1234");

    Librarian *librarian1 = new Librarian("l2", "Neha", "neha@gmail.com", "password");

    lib->addUser(member1);
    lib->addUser(librarian1);

    // Step 4: Librarian adds books (delegates to Inventory via Facade)
    Book *book1 = new Book("B1", "C++ Design Patterns", "Erich Gamma", "121");
    Book *book2 = new Book("B2", "Clean Code", "Robert Martin", "122");
    Book *book3 = new Book("B3", "Effective C++", "Scott Meyers", "123");

    lib->addBook(book1);
    lib->addBook(book2);
    lib->addBook(book3);

    cout << "\n📚 Current Inventory:\n";
    lib->listsBooks();

    // Step 5: Borrowing process
    cout << "\n=== Borrow Flow ===\n";
    lib->borrowBook("M1", book1); // member borrows book1

    cout << "\n📚 Inventory After Borrow:\n";
    lib->listsBooks();

    // Step 6: Returning process
    cout << "\n=== Return Flow ===\n";
    lib->returnBook("M1", book1); // member returns book1

    cout << "\n📚 Inventory After Return:\n";
    lib->listsBooks();

    cout << "\n✅ Library System Execution Completed Successfully!\n";

    return 0;
}
