#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
#include <vector>
#include <memory>
#include "Level.h"

class ParkingLot
{
private:
    static std::shared_ptr<ParkingLot> instance;
    std::vector<std::shared_ptr<Level>> levels;

    ParkingLot() {}

public:
    static std::shared_ptr<ParkingLot> getInstance()
    {
        if (instance == nullptr)
        {
            instance = std::make_shared<ParkingLot>();
        }
        return instance;
    }

    void addLevel(std::shared_ptr<Level> level)
    {
        levels.push_back(level);
    }

    bool parkVehicle(std::shared_ptr<Vehicle> vehicle)
    {
        for (auto &level : levels)
        {
            if (level->parkVehicle(vehicle))
            {
                return true;
            }
        }
        return false;
    }

    bool unparkVehicle(std::shared_ptr<Vehicle> vehicle)
    {
        for (auto &level : levels)
        {
            if (level->unparkVehicle(vehicle))
            {
                return true;
            }
        }
        return false;
    }

    void displayAvailability() const
    {
        for (const auto &level : levels)
        {
            level->displayAvailability();
        }
    }
};

// Initialize the static instance to nullptr
std::shared_ptr<ParkingLot> ParkingLot::instance = nullptr;

#endif
