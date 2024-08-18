#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <memory>
#include "vehicletype/Vehicle.h"
#include "vehicletype/VehicleType.h"
#include <stdexcept>

class ParkingSpot {
private:
    int spotNumber;
    VehicleType vehicleType;
    std::shared_ptr<Vehicle> parkedVehicle;

public:
    ParkingSpot(int spotNumber)
        : spotNumber(spotNumber), vehicleType(VehicleType::CAR), parkedVehicle(nullptr) {}

    bool isAvailable() const {
        return parkedVehicle == nullptr;
    }

    void parkVehicle(std::shared_ptr<Vehicle> vehicle) {
        if (isAvailable() && vehicle->getType() == vehicleType) {
            parkedVehicle = vehicle;
        } else {
            throw std::invalid_argument("Invalid vehicle type or spot already occupied.");
        }
    }

    void unparkVehicle() {
        parkedVehicle.reset();
    }

    VehicleType getVehicleType() const {
        return vehicleType;
    }

    std::shared_ptr<Vehicle> getParkedVehicle() const {
        return parkedVehicle;
    }

    int getSpotNumber() const {
        return spotNumber;
    }
};

#endif
