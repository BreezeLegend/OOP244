#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
namespace sdds {
	bool Parking::isEmpty() {
		return file_name == nullptr;
	}
	void Parking::parkingStatus() {
		std::cout << "****** Seneca Valet Parking ******\n";
		std::cout << "*****  Available spots: " << std::setw(4) << std::left << (num_spots - parked_vehicles) << " *****\n";
	}
	void Parking::parkVehicle() {
		if (parked_vehicles == num_spots) {
			std::cout << "Parking is full\n";
			return;
		}
		Vehicle* v = nullptr;
		switch ((int)vehicle_menu) {
		case 1:
			v = new Car();
			break;
		case 2:
			v = new Motorcycle();
			break;
		case 3:
			std::cout << "Parking cancelled\n";
			return;
		}
		std::cout << "\n";
		v->setCsv(false);
		v->read();
		for (int i = 0; i < num_spots; i++) {
			if (spots[i] == nullptr) {
				spots[i] = v;
				parked_vehicles++;
				v->setParkingSpot(i + 1);
				break;
			}
		}
		std::cout << "\nParking Ticket\n";
		v->write();
		std::cout << "\n";
	}
	void Parking::returnVehicle() {
		std::cout << "Return Vehicle\n";
		std::cout << "Enter Licence Plate Number: ";
		std::string input;
		do {
			std::getline(std::cin, input);
			if (input.size() < 1 || input.size() > 8) {
				std::cout << "Invalid License Plate, try again: ";
			}
		} while (input.size() < 1 || input.size() > 8);
		Vehicle* v = nullptr;
		for (int i = 0; i < num_spots; i++) {
			if (spots[i] != nullptr && *spots[i] == input.c_str()) {
				v = spots[i];
				parked_vehicles--;
				std::cout << "\nReturning: \n";
				v->write();
				std::cout << "\n";
				delete v;
				spots[i] = nullptr;
				return;
			}
		}
		if (v == nullptr) {
			std::cout << "License plate " << input << " Not found\n";
		}
	}
	void Parking::listParkedVehicles() {
		std::cout << "*** List of parked vehicles ***" << std::endl;
		for (int i = 0; i < num_spots; i++) {
			if (spots[i] != nullptr) {
				spots[i]->write();
				std::cout << "-------------------------------\n";
			}
		}
	}
	bool Parking::closeParking() {
		if (parked_vehicles == 0) {
			std::cout << "Closing Parking\n";
			return true;
		}
		std::cout << "This will Remove and tow all remaining vehicles from the parking!\nAre you sure? (Y)es/(N)o: ";
		std::string input;
		do {
			std::getline(std::cin, input);
			if (input != "Y" && input != "y" && input != "N" && input != "n") {
				std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		} while (input != "Y" && input != "y" && input != "N" && input != "n");
		if (input == "N" || input == "n") {
			std::cout << "Aborted!" << std::endl;
			return false;
		}
		std::cout << "Closing Parking\n";
		for (int i = 0; i < num_spots; i++) {
			if (spots[i] != nullptr) {
				std::cout << "\n";
				std::cout << "Towing request\n*********************\n";
				spots[i]->write();
				delete spots[i];
				spots[i] = nullptr;
				parked_vehicles--;
			}
		}
		return true;
	}
	bool Parking::exitParkingApp() {
		std::cout << "This will terminate the program!\n";
		std::cout << "Are you sure? (Y)es/(N)o: ";
		while (true) {
			std::string resp;
			std::getline(std::cin, resp);
			if (resp == "Y" || resp == "y") {
				std::cout << "Exiting program!\n";
				return true;
			}
			else if (resp == "N" || resp == "n") {
				return false;
			}
			else {
				std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		}
	}
	bool Parking::loadDataFile() {
		if (!isEmpty()) {
			std::ifstream file(file_name);
			if (file.is_open()) {
				while (file.good() && parked_vehicles < num_spots) {
					Vehicle* v = nullptr;
					char type = 'j';
					file >> type;
					if (type == 'M') {
						v = new Motorcycle();
					}
					else if (type == 'C') {
						v = new Car();
					}
					file >> type;
					if (v != nullptr) {
						v->setCsv(true);
						v->read(file);
						v->setCsv(false);
						spots[v->getParkingSpot() - 1] = v;
						parked_vehicles++;
					}
				}
				file.close();
				return true;
			}
			else {
				return false;
			}
			return true;
		}
		else {
			return false;
		}
	}
	void Parking::saveDataFile() {
		if (!isEmpty()) {
			ofstream file(file_name);
			if (file.is_open()) {
				for (int i = 0; i < num_spots; i++) {
					if (spots[i] != nullptr) {
						bool wasCsv = spots[i]->isCsv();
						spots[i]->setCsv(true);
						spots[i]->write(file);
						spots[i]->setCsv(wasCsv);
					}
				}
			}
		}
	}

	Parking::Parking(const char* name, int noOfSpots) : num_spots(noOfSpots), spots{ nullptr }, parked_vehicles(0), main_menu(nullptr), vehicle_menu(nullptr)   {
		if (name == nullptr || strlen(name) == 0 || noOfSpots < 10 || noOfSpots > max_parking_spots) {
			file_name = nullptr;
		}
		else {
			file_name = new char[strlen(name) + 1];
			strcpy(file_name, name);
		}
		if (loadDataFile()) {
			main_menu = { "Parking Menu, select an action:" };
			main_menu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			vehicle_menu = { "Select type of the vehicle:", 1 };
			vehicle_menu << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			std::cout << "Error in data file\n";
		}
	}

	Parking::~Parking() {
		if (file_name != nullptr) {
			saveDataFile();
			delete[] file_name;
		}
	}

	int Parking::run() {
		if (!isEmpty()) {
			while (true) {
				parkingStatus();
				switch ((int)main_menu) {
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