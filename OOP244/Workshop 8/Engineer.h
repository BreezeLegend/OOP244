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
	class Engineer : public Employee
	{
	private:

		int level;

	public:

		Engineer(double sal, int level);

		double getSalary(int workedHours);

		ostream& display(ostream& out);

	};




}
