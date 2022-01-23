/* Citation and Sources
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Victor Hasnat
-----------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshop assignments.
-----------------------------------------------------
*/

#pragma once
#include "Menu.h"
namespace sdds
{
    class Parking
    {
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
        Parking(const char* name);
        ~Parking();

        Parking(const Parking& other) = delete;
        Parking& operator=(const Parking& other) = delete;

        int run();
    };
}
