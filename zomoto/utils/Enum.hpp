#ifndef ENUM_HPP
#define ENUM_HPP

#include <string>
#include <unordered_map>
using namespace std;

// Defining enums classes for Order Status, Delivery Status, PaymentMethods and PaymentStatus
enum class OrderStatus{
    CREATED,
    CONFIRMED,
    PREPARING,
    READY_FOR_DELIVERY,
    OUT_FOR_DELIVERY,
    DELIVERED,
    CANCELLED
};

enum class DeliveryStatus {
    PENDING,
    IN_TRANSIT,
    DELIVERED,
    FAILED
};

enum class PartnerStatus {
    AVAILABLE,
    BUSY,
    OFFLINE
};

enum class VehicleType {
    BIKE,
    CAR,
    SCOOTER,
    BICYCLE
};

enum class NotificationType {
    PUSH_NOTIFICATION,
    EMAIL,
    SMS
};

// Stringify functions for each enum class
inline string to_string(OrderStatus status) {
    switch(status) {
        case OrderStatus::CREATED: return "CREATED";
        case OrderStatus::CONFIRMED: return "CONFIRMED";
        case OrderStatus::PREPARING: return "PREPARING";
        case OrderStatus::READY_FOR_DELIVERY: return "READY_FOR_DELIVERY";
        case OrderStatus::OUT_FOR_DELIVERY: return "OUT_FOR_DELIVERY";
        case OrderStatus::DELIVERED: return "DELIVERED";
        case OrderStatus::CANCELLED: return "CANCELLED";
        default: return "UNKNOWN";
    }
}

inline string to_string(DeliveryStatus status) {
    switch(status) {
        case DeliveryStatus::PENDING: return "PENDING";
        case DeliveryStatus::IN_TRANSIT: return "IN_TRANSIT";
        case DeliveryStatus::DELIVERED: return "DELIVERED";
        case DeliveryStatus::FAILED: return "FAILED";
        default: return "UNKNOWN";
    }
}

inline string to_string(PartnerStatus status) {
    switch(status) {
        case PartnerStatus::AVAILABLE: return "AVAILABLE";
        case PartnerStatus::BUSY: return "BUSY";
        case PartnerStatus::OFFLINE: return "OFFLINE";
        default: return "UNKNOWN";
    }
}

inline string to_string(VehicleType type) {
    switch(type) {
        case VehicleType::BIKE: return "BIKE";
        case VehicleType::CAR: return "CAR";
        case VehicleType::SCOOTER: return "SCOOTER";
        case VehicleType::BICYCLE: return "BICYCLE";
        default: return "UNKNOWN";
    }
}

inline string to_string(NotificationType type) {
    switch(type) {
        case NotificationType::PUSH_NOTIFICATION: return "PUSH_NOTIFICATION";
        case NotificationType::EMAIL: return "EMAIL";
        case NotificationType::SMS: return "SMS";
        default: return "UNKNOWN";
    }
}

#endif