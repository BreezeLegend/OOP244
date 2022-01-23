/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 22, 2020
*/

#pragma once
#include <iostream>
using namespace std;
namespace sdds
{
	class Employee
	{
	private: 
		const int h_emp;
		double h_sal;


	protected:
		int getMinHours() const
		{
			return h_emp;
		}

		double getHourlySalary() const
		{
			return h_sal;
		}


	public:
	
		Employee(double h_sal, const int h_emp);
		
		virtual double getSalary(int workedHours)
		{
			return 0;
		}

		virtual ostream& display(ostream& out = cout)
		{
			return out;
		}

		virtual ~Employee()
		{

		}

		friend ostream& operator<<(ostream& str,Employee& emp);

	};



}
