/**
 * Super Factory reponsible for creating the sub_factories
 * 
 */
#ifndef NOTIFICATION_SUPER_FACTORY_INTERFACE_HPP
#define NOTIFICATION_SUPER_FACTORY_INTERFACE_HPP

#include <string>
#include <memory>
#include "../builder/NotificationBuilder.hpp"
using namespace std;

class NotificationFactory {
    public :
        virtual ~NotificationFactory() = default;

        // createBuilder() creating_builder 
        virtual unique_ptr<NotificationBuilder> createBuilder() const = 0;
};

#endif