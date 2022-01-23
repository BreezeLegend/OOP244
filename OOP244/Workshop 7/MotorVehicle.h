#pragma once
#include <iostream>
#include <string.h>
namespace sdds
{
	class MotorVehicle
	{
	protected:
		char m_plate[32];
		char m_address[64];
		int m_year;

	public:

		MotorVehicle(const char* plate,  int year);

		void moveTo(const char* address);

		std::ostream& write(std::ostream& os);

		std::istream& read(std::istream& in);

		friend std::ostream& operator<<(std::ostream& os, MotorVehicle motorvehicle);

		friend std::istream& operator>>(std::istream& in, MotorVehicle& motorvehicle);
	
	};


}