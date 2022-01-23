#include <iostream>
#include <string.h>
#include <iomanip>
#include "MotorVehicle.h"
using namespace std;

namespace sdds
{

	MotorVehicle::MotorVehicle(const char* plate, int year)
	{
		strncpy(m_plate, plate, 32);
		strncpy(m_address, "Factory", 64);
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strcmp(m_address, address))
		{
			cout << "|" << right << setw(10) << m_plate << "|" << " |" << setw(20) << m_address << " --->--- " << left << setw(20) << address << "|" << endl;
			strncpy(m_address, address, 64);
		}
	}

	ostream& MotorVehicle::write(std::ostream& os)
	{
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;
	}

	istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		in.ignore();
		cout << "License plate: ";
		in.getline(m_plate, 32);
		cout << "Current location: ";
		in.getline(m_address, 64);
		return in;
	}

	ostream& operator<<(std::ostream& os, MotorVehicle motorvehicle )
	{
		return motorvehicle.write(os);
	}

	istream& operator>>(std::istream& in, MotorVehicle& motorvehicle)
	{
		return motorvehicle.read(in);
	}

}