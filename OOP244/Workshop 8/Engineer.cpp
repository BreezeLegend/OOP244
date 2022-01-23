/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 22, 2020
*/

#include "Engineer.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds
{ 

	Engineer::Engineer(double sal, int level) : Employee(sal, 30)
	{
		this->level = level;
	}

	double Engineer::getSalary(int workedHours)
	{
		double money = 0;
		money += workedHours * getHourlySalary();
		money += 40 * level;
		if(workedHours < getMinHours())
		money *= 0.8;
		return money;
	}

	ostream& Engineer::display(ostream& out)
	{
		out << "Engineer" << "\n";
		out << setw(20) << right << "Level: " << level << "\n";
		out << setw(20) << right << "Pay Rate: " << getHourlySalary() << "\n";
		out << setw(20) << right << "Min Hours: " << getMinHours() << "\n";
		return out;
	}

}