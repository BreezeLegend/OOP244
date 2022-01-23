/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 22, 2020
*/

#include <iostream>
#include "Employee.h"
using namespace std;

namespace sdds
{
	Employee::Employee(double sal, const int emp) : h_emp(emp), h_sal(sal)
	{

	}

	ostream& operator<<(ostream& str, Employee& emp)
	{
		emp.display(str);
		return str;
	}



}