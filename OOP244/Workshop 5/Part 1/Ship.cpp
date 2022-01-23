/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 24, 2020
*/
#include <string.h>
#include <iostream>
#include "Ship.h"
using namespace std;
namespace sdds
{


	Ship::Ship()
	{
		m_engCnt = -1;
	}

	Ship::Ship(const char type[], Engine eng[], int size)
	{
		if (eng != nullptr && size > 0 && size < 11)
		{
			strncpy(m_type, type, TYPE_MAX_SIZE);
			memcpy(m_engines, eng, size * sizeof(Engine));
			m_engCnt = size;
		}
		else
		{
			m_engCnt = size;
		}
	}

	 Ship::operator bool() const
	{
		return m_engCnt != -1;
	}

	Ship& Ship::operator+=(Engine engine)
	{
		if (m_engCnt != -1 && m_engCnt < 10)
		{
			m_engines[m_engCnt] = engine;
			m_engCnt++;
		}
		else
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		return *this;
	}

	double Ship::totalpower() const 
	{
		double total = 0;
		for (int i = 0; i < m_engCnt; i++)
		{
			total += m_engines[i].get();
		}
		return total * 5;
	}

	bool Ship::operator<(double power) const
	{
		return totalpower() < power;
	}

	void Ship::display() const
	{
		if (!*this)
		{
			cout << "No available data" << endl;
			return;
		}
		cout << m_type << " - " << totalpower() << endl;
		for (int i = 0; i < m_engCnt; i++)
		{
			m_engines[i].display();
		}
	}

	bool operator<(double power, const Ship& theShip)
	{
		return power < theShip.totalpower();
	}
}
