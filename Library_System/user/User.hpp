#ifndef USER_HPP
#define USER_HPP

#include <string>
using namespace std;

class User
{
    // Data Fields
protected:
    string userId;
    string name;
    string email;
    string password;

public:
    // Methods - Constructor
    User(const string &userId, const string &name, const string &email, const string &password) : userId(userId), name(name), email(email), password(password) {};

    virtual ~User() {}

    // Getters
    string getId()
    {
        return userId;
    }
    string getName()
    {
        return name;
    }

    // login
    bool login(const string &user_email, const string &pass)
    {
        if (user_email == email && pass == password)
        {
            return true;
        }
        return false;
    }
};

#endif