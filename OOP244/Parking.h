#pragma once
#include "Menu.h"
#include "Vehicle.h"
namespace sdds {
    constexpr int max_parking_spots{ 100 };

    class Parking {
        int num_spots;
        Vehicle* spots[max_parking_spots];
        int parked_vehicles;
        char* file_name;
        Menu main_menu;
        Menu vehicle_menu;

        bool isEmpty();
        void parkingStatus();
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicles();
        bool closeParking();
        bool exitParkingApp();
        bool loadDataFile();
        void saveDataFile();

    public:
        Parking(const char* name, int noOfSpots);
        ~Parking();

        Parking(const Parking& other) = delete;
        Parking& operator=(const Parking& other) = delete;

        int run();
    };
}