/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 24, 2020
*/

#pragma once
#include "Engine.h"
namespace sdds
{
 const double MIN_STD_POWER = 90.111;
 const double MAX_STD_POWER = 99.999;

	class Ship
	{ 
	private:
	Engine m_engines[10];
	char m_type[TYPE_MAX_SIZE];
	int m_engCnt;
	

	public:
    double totalpower() const;

	Ship();

	Ship(const char type[], Engine eng[], int size);

	explicit operator bool() const;

	Ship& operator+=(Engine engine);

	bool operator<(double power) const;

	void display() const;	
};
	bool operator<(double power, const Ship& theShip);
}