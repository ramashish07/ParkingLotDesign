#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "VehicleType.h"

class Vehicle {
protected:
    std::string licensePlate;
    VehicleType type;

public:
    Vehicle(const std::string& licensePlate, VehicleType type)
        : licensePlate(licensePlate), type(type) {}

    virtual VehicleType getType() const {
        return type;
    }

    virtual ~Vehicle() = default;
};

#endif
