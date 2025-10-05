#ifndef BORROWINGMANAGER_H
#define BORROWINGMANAGER_H

#include "user/Member.hpp"
#include "notificationManager.hpp"

class BorrowingManager
{
    NotificationManager *notifyMgr;

public:
    BorrowingManager(NotificationManager *nm) : notifyMgr(nm) {}

    void borrowBook(User *user, Book *book)
    {
        Member *member = dynamic_cast<Member *>(user);
        if (member)
        {
            member->borrowBook(book);
            notifyMgr->notify("You borrowed: " + book->getTitle(), member->getName());
        }
    }

    void returnBook(User *user, Book *book)
    {
        Member *member = dynamic_cast<Member *>(user);
        if (member)
        {
            member->returnBook(book);
            notifyMgr->notify("You returned: " + book->getTitle(), member->getName());
        }
    }
};
#endif
