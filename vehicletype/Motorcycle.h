#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& licensePlate)
        : Vehicle(licensePlate, VehicleType::MOTORCYCLE) {}
};

#endif
