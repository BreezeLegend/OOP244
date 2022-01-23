/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 17, 2020
*/
#include <string.h>
#include <iostream>
#include "Saiyan.h"

using namespace std;
namespace sdds
{
	Saiyan::Saiyan()
	{
		m_dob = MAX_DOB + 1;
		m_power = 0;
		m_super = false;
	}

	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		set(name, dob, power);

	}

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		if(name != nullptr && strlen(name) < MAX_NAME && strlen(name) > 0 && dob >= 0 && dob <= MAX_DOB && power >= 0)
		{
			strncpy(m_name, name, MAX_NAME);
			m_dob = dob;
			m_power = power;
			m_super = super;
		
		}
		else
		{
			m_dob = MAX_DOB + 1;
			m_power = 0;
			m_super = false;
		}

	}

	bool Saiyan::isValid() const
	{
		return m_dob != MAX_DOB + 1;
	}

	void Saiyan::display() const
	{
		if (!isValid())
		{
			cout << "Invalid Saiyan!" << endl;
			return;
		}
		cout << m_name << endl;
		cout << "DOB: " << m_dob << endl;
		cout << "Power: " << m_power << endl;
		cout << "Super: " << (m_super ? "yes" : "no") << endl;
	}

	bool Saiyan::fight(const Saiyan& other) const
	{
		return isValid() && other.isValid() && m_power > other.m_power;
	}

}