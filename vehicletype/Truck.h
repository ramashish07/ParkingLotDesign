#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const std::string& licensePlate)
        : Vehicle(licensePlate, VehicleType::TRUCK) {}
};

#endif
