/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 22, 2020
*/

#pragma once
#include "Employee.h"
namespace sdds
{
	class Doctor : public Employee
	{
	private:

		char t_doc[32];
		bool spec;

	public:

		Doctor(const char doc[], double sal, const int m_hours, bool spec = false);

		double getSalary(int workedHours);

		ostream& display(ostream& out);

	};




}