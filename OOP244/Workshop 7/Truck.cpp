#include <iostream>
#include <string.h>
#include <algorithm>
#include "Truck.h"
#include "MotorVehicle.h"
using namespace std;

namespace sdds
{

	Truck::Truck(const char* plate, int year, double cap, const char* address) : MotorVehicle(plate, year)
	{
		m_cap = cap;
		m_load = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		if (m_load == m_cap)
		{
			return false;
		}
		m_load = min(m_load + cargo, m_cap);
		return true;
	}

	bool Truck::unloadCargo()
	{
		if (m_load == 0)
		{
			return false;
		}
		m_load = 0;
		return true;
	}

	std::ostream& Truck::write(std::ostream& os)
	{
		os << "| " << m_year << " | " << m_plate << " | " << m_address << " | " << m_load << "/" << m_cap;
		return os;
	}

	std::istream& Truck::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		in.ignore();
		cout << "License plate: ";
		in.getline(m_plate, 32);
		cout << "Current location: ";
		in.getline(m_address, 64);
		cout << "Capacity: ";
		in >> m_cap;
		cout << "Cargo: ";
		in >> m_load;
		return in;
	}

	std::ostream& operator<<(std::ostream& os,  Truck& truck)
	{
		return truck.write(os);
	}

	std::istream& operator>>(std::istream& in, Truck& truck)
	{
		return truck.read(in);
	}

}