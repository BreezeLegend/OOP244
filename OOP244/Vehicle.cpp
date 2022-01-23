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

#include "Vehicle.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
namespace sdds
{
	int strcicmp(char const* a, char const* b)
	{
		for (;; a++, b++)
		{
			int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
			if (d != 0 || !*a)
				return d;
		}
	}

	void Vehicle::setEmpty()
	{
		if (m_model != nullptr)
			delete[] m_model;
		m_model = nullptr;
		m_parkingnum = -1;
	}

	bool Vehicle::isEmpty() const
	{
		return m_parkingnum == -1;
	}

	const char* Vehicle::getLicensePlate() const
	{
		return m_plate;
	}

	const char* Vehicle::getMakeModel() const
	{
		return m_model;
	}

	void Vehicle::setMakeModel(const char* model)
	{
		if (model != nullptr && strlen(model) > 0)
		{
			if (m_model != nullptr)
				delete[] m_model;
			m_model = new char[strlen(model) + 1];
			strncpy(m_model, model, strlen(model));
			m_model[strlen(model)] = 0;
		}
		else
		{
			setEmpty();
		}
	}

	Vehicle::Vehicle()
	{
		m_model = nullptr;
		m_parkingnum = -1;
	}

	Vehicle::Vehicle(const char plate[], const char* model)
	{
		if (plate != nullptr && strlen(plate) > 0 && strlen(plate) < 9 && model != nullptr && strlen(model) > 1)
		{
			strncpy(m_plate, plate, 8);
			m_model = new char[strlen(model) + 1];
			strncpy(m_model, model, strlen(model));
			m_model[strlen(model)] = 0;
			m_parkingnum = 0;
		}
		else
		{
			m_model = nullptr;
			m_parkingnum = -1;
		}
	}

	Vehicle::~Vehicle()
	{
		if (m_model != nullptr)
			delete[] m_model;
	}

	int Vehicle::getParkingSpot() const
	{
		return m_parkingnum;
	}

	void Vehicle::setParkingSpot(int spot)
	{
		m_parkingnum = spot;
	}

	bool operator==(const Vehicle& first, const char* plate)
	{
		if (first.m_plate == nullptr || plate == nullptr || strlen(first.m_plate) == 0 || strlen(plate) == 0)
			return false;
		return !strcicmp(first.m_plate, plate);
	}

	bool operator==(const Vehicle& first, const Vehicle& other)
	{
		if (first.m_plate == nullptr || other.m_plate == nullptr || strlen(first.m_plate) == 0 || strlen(other.m_plate) == 0)
			return false;
		return !strcicmp(first.m_plate, other.m_plate);
	}

	istream& Vehicle::read(istream& str)
	{
		if (isCsv())
		{
			str >> m_parkingnum;
			str.ignore();
			string temp;
			getline(str, temp, ',');
			transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
			strncpy(m_plate, temp.c_str(), 8);
			getline(str, temp, ',');
			if (m_model != nullptr)
				delete[] m_model;
			m_model = new char[min((int)strlen(temp.c_str()), 60) + 1];
			strncpy(m_model, temp.c_str(), min((int)strlen(temp.c_str()), 60));
			m_model[min((int)strlen(temp.c_str()), 60)] = 0;
		}
		else
		{
			cout << "Enter Licence Plate Number: ";
			string temp;
			do
			{
				getline(str, temp);
				transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
				if (strlen(temp.c_str()) > 8 || strlen(temp.c_str()) < 1)
				{
					cout << "Invalid Licence Plate, try again: ";
				}
				else
				{
					strncpy(m_plate, temp.c_str(), 8);
				}
			} while (strlen(temp.c_str()) > 8 || strlen(temp.c_str()) < 1);
			cout << "Enter Make and Model: ";
			do
			{
				getline(str, temp);
				if (strlen(temp.c_str()) > 60 || strlen(temp.c_str()) < 2)
				{
					cout << "Invalid Make and model, try again: ";
				}
				else
				{
					if (m_model != nullptr)
						delete[] m_model;
					m_model = new char[strlen(temp.c_str()) + 1];
					strncpy(m_model, temp.c_str(), strlen(temp.c_str()));
					m_model[strlen(temp.c_str())] = 0;
				}
			} while (strlen(temp.c_str()) > 60 || strlen(temp.c_str()) < 2);
			m_parkingnum = 0;
		}
		if (str.fail())
		{
			setEmpty();
		}
		return str;
	}

	ostream& Vehicle::write(ostream& str) const
	{
		if (isEmpty())
		{
			str << "Invalid Vehicle Object\n";
			return str;
		}
		if (isCsv())
		{
			str << m_parkingnum << "," << m_plate << "," << m_model << ",";
		}
		else
		{
			str << "Parking Spot Number: " << (m_parkingnum == 0 ? "N/A" : to_string(m_parkingnum)) << "\n";
			str << "Licence Plate: " << m_plate << "\n";
			str << "Make and Model: " << m_model << "\n";
		}
		return str;
	}
}