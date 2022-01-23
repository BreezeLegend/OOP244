#pragma once
#include <iostream>
#include <string.h>
#include "MotorVehicle.h"
using namespace std;
namespace sdds
{
	class Truck : public MotorVehicle
	{
	private:
		double m_cap;
		double m_load;

	public:

		Truck(const char* plate, int year, double cap, const char* address);

		bool addCargo(double cargo);

		bool unloadCargo();

		std::ostream& write(std::ostream& os);

		std::istream& read(std::istream& in);

		friend std::ostream &operator<<(std::ostream& os, Truck& truck);

		friend std::istream &operator>>(std::istream& in, Truck& truck);

		 
		
	};


}
