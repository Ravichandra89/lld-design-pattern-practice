#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <unordered_map>
#include "../user/User.hpp"

class userManager
{
    unordered_map<string, User *> users;

public:
    void addUser(User *user)
    {
        users[user->getId()] = user;
    }

    User* getUser(const string& id) {
        return (users.count(id)) ? users[id] : nullptr;
    }
};

#endif