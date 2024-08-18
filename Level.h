#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>
#include <memory>
#include "ParkingSpot.h"
#include "vehicletype/Vehicle.h"

class Level {
private:
    int floor;
    std::vector<std::shared_ptr<ParkingSpot>> parkingSpots;

public:
    Level(int floor, int numSpots) : floor(floor), parkingSpots(numSpots) {
        for (int i = 0; i < numSpots; ++i) {
            parkingSpots[i] = std::make_shared<ParkingSpot>(i);
        }
    }

    bool parkVehicle(std::shared_ptr<Vehicle> vehicle) {
        for (auto& spot : parkingSpots) {
            if (spot->isAvailable() && spot->getVehicleType() == vehicle->getType()) {
                spot->parkVehicle(vehicle);
                return true;
            }
        }
        return false;
    }

    bool unparkVehicle(std::shared_ptr<Vehicle> vehicle) {
        for (auto& spot : parkingSpots) {
            if (!spot->isAvailable() && spot->getParkedVehicle() == vehicle) {
                spot->unparkVehicle();
                return true;
            }
        }
        return false;
    }

    void displayAvailability() const {
        std::cout << "Level " << floor << " Availability:" << std::endl;
        for (const auto& spot : parkingSpots) {
            std::cout << "Spot " << spot->getSpotNumber() << ": "
                      << (spot->isAvailable() ? "Available" : "Occupied") << std::endl;
        }
    }
};

#endif
