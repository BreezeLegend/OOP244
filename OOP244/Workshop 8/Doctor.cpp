/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 22, 2020
*/
#include <string.h>
#include "Doctor.h"
#include <iomanip>
#include <iostream>

using namespace std;
namespace sdds
{

	Doctor::Doctor(const char doc[], double sal, const int m_hours, bool spec) : Employee(sal, m_hours)
	{
		strncpy(t_doc, doc, 32);
		this->spec = spec;
	}

	double Doctor::getSalary(int workedHours)
	{
		double money = 0;
		if (workedHours <= getMinHours())
		{
			money += workedHours * getHourlySalary();
		}
		else
		{
			money += getMinHours() * getHourlySalary();
			money += (workedHours - getMinHours()) * getHourlySalary() * 1.5;
		}
		if (spec)
			money += 2000;
		return money;
	}

	ostream& Doctor::display(ostream& out)
	{
		out << "Doctor\n";
		out << setw(16) << right << "Type: " << t_doc;
		if (spec)
		{
			out << " (specialist)";
		}
		out << "\n";
		out << setw(16) << right << "Pay Rate: " << getHourlySalary() << "\n";
		out << setw(16) << right << "Min Hours: " << getMinHours() << "\n";
		return out;
	}


}