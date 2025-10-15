#ifndef INTEFACE_PARTNER_HPP
#define INTEFACE_PARTNER_HPP

#include <string>
#include "../utils/Enum.hpp"
using namespace std;

class IPartner
{
protected:
    string name;
    Rating rating;

public:
    IPartner(const string &pName, Rating pRating) : name(pName), rating(pRating) {};

    virtual void performKyc() = 0;
    virtual ~IPartner() = default;

    string getName() const
    {
        return name;
    }

    Rating getRating() const
    {
        return rating;
    }

    void setRating(Rating pRating)
    {
        rating = pRating;
    }
};

#endif