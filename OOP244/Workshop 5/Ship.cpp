/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 27, 2020
*/
#include <string.h>
#include <iostream>
#include <iomanip>
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
			m_type = new char[strlen(type) + 1];
			m_engines = new Engine[size];
			strncpy(m_type, type, strlen(type) + 1);
			memcpy(m_engines, eng, size * sizeof(Engine));
			m_engCnt = size;
		}
		else
		{
			m_engCnt = size;
		}
	}

	Ship::~Ship()
	{
		if (m_engCnt != -1)
		{
			delete[] m_type;
			delete[] m_engines;
		}
	}

	 Ship::operator bool() const
	{
		return m_engCnt != -1;
	}

	Ship& Ship::operator+=(Engine engine)
	{
		if (m_engCnt != -1)
		{
			Engine* new_engines = new Engine[m_engCnt + 1];
			memcpy(new_engines, m_engines, m_engCnt * sizeof(Engine));
			new_engines[m_engCnt] = engine;
			delete[] m_engines;
			m_engines = new_engines;
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
		cout << m_type << " - " << setw(6) << fixed << setprecision(2) << totalpower() << resetiosflags(ios::fixed) << setprecision(-1) << endl;
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
