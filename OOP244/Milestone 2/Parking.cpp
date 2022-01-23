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

#include "Parking.h"
#include <string>
namespace sdds
{
	bool Parking::isEmpty()
	{
		return file_name == nullptr;
	}
	void Parking::parkingStatus()
	{
		std::cout << "****** Seneca Valet Parking ******\n";
	}
	void Parking::parkVehicle()
	{
		int choice = vehicle_menu;
		switch (choice)
		{
		case 1:
			std::cout << "Parking Car";
			break;
		case 2:
			std::cout << "Parking Motorcycle";
			break;
		case 3:
			std::cout << "Cancelled parking";
			break;
		}
		std::cout << "\n";
	}
	void Parking::returnVehicle()
	{
		std::cout << "Returning Vehicle\n";
	}
	void Parking::listParkedVehicles()
	{
		std::cout << "Listing Parked Vehicles\n";
	}
	bool Parking::closeParking()
	{
		std::cout << "Closing Parking\n";
		return true;
	}
	bool Parking::exitParkingApp()
	{
		std::cout << "This will terminate the program!\n";
		std::cout << "Are you sure? (Y)es/(N)o: ";
		while (true)
		{
			std::string resp;
			std::getline(std::cin, resp);
			if (resp == "Y" || resp == "y")
			{
				std::cout << "Exiting program!\n";
				return true;
			}
			else if (resp == "N" || resp == "n")
			{
				return false;
			}
			else
			{
				std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		}
	}
	bool Parking::loadDataFile()
	{
		if (!isEmpty())
		{
			std::cout << "loading data from ";
			std::cout << file_name << "\n";
			return true;
		}
		else
		{
			return false;
		}
	}
	void Parking::saveDataFile()
	{
		if (!isEmpty())
		{
			std::cout << "Saving data into ";
			std::cout << file_name << "\n";
		}
	}

	Parking::Parking(const char* name) : main_menu(nullptr), vehicle_menu(nullptr)
	{
		if (name == nullptr || strlen(name) == 0)
		{
			file_name = nullptr;
		}
		else
		{
			file_name = new char[strlen(name) + 1];
			strcpy(file_name, name);
		}
		if (loadDataFile())
		{
			main_menu = { "Parking Menu, select an action:" };
			main_menu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			vehicle_menu = { "Select type of the vehicle:", 1 };
			vehicle_menu << "Car" << "Motorcycle" << "Cancel";
		}
		else
		{
			std::cout << "Error in data file\n";
		}
	}

	Parking::~Parking()
	{
		if (file_name != nullptr)
		{
			saveDataFile();
			delete[] file_name;
		}
	}

	int Parking::run()
	{
		if (!isEmpty())
		{
			while (true)
			{
				parkingStatus();
				int choice = main_menu;
				switch (choice)
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkedVehicles();
					break;
				case 4:
					if (closeParking()) return 0;
					break;
				case 5:
					if (exitParkingApp()) return 0;
					break;
				}
			}
		}
		return 1;
	}
}