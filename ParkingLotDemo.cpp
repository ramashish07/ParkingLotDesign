#include "ParkingLot.h"
#include "vehicletype/Car.h"
#include "vehicletype/Truck.h"
#include "vehicletype/Motorcycle.h"

class ParkingLotDemo {
public:
    static void run() {
        std::shared_ptr<ParkingLot> parkingLot = ParkingLot::getInstance();
        parkingLot->addLevel(std::make_shared<Level>(1, 100));
        parkingLot->addLevel(std::make_shared<Level>(2, 80));

        std::shared_ptr<Vehicle> car = std::make_shared<Car>("ABC123");
        std::shared_ptr<Vehicle> truck = std::make_shared<Truck>("XYZ789");
        std::shared_ptr<Vehicle> motorcycle = std::make_shared<Motorcycle>("M1234");

        // Park vehicles
        parkingLot->parkVehicle(car);
        parkingLot->parkVehicle(truck);
        parkingLot->parkVehicle(motorcycle);

        // Display availability
        parkingLot->displayAvailability();

        // Unpark vehicle
        parkingLot->unparkVehicle(motorcycle);

        // Display updated availability
        parkingLot->displayAvailability();
    }
};

int main() {
    ParkingLotDemo::run();
    return 0;
}
