/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 13, 2020
*/

#include <iostream>
#include "Train.h"
#include "Cargo.h"
#include <algorithm>
#include <iomanip>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
	void Train::initialize(const char* name, int id)
	{
		Valid_Cargo = nullptr;
		if (name == nullptr || strlen(name) == 0 || id < 0)
		{
			Valid_ID = -1;
			return;
		}
		strcpy(Valid_Name, name);
		Valid_ID = id;
	}

	bool Train::isValid() const
	{
		return Valid_ID != -1;
	}

	void Train::loadCargo(Cargo car)
	{
		if (Valid_Cargo != nullptr)
		{
			delete Valid_Cargo;
		}
		Valid_Cargo = new Cargo;
		memcpy(Valid_Cargo, &car, sizeof(Cargo));
	}

	bool Train::swapCargo(Train& other)
	{
		if (isValid() && Valid_Cargo != nullptr && other.isValid() && other.Valid_Cargo != nullptr)
		{
			swap(Valid_Cargo, other.Valid_Cargo);
			return true;
		}
		else
			return false;
	}

	bool Train::increaseCargo(double weight)
	{
		if (isValid() && Valid_Cargo != nullptr && Valid_Cargo->getWeight() < MAX_WEIGHT)
		{
			Valid_Cargo->setWeight(min(MAX_WEIGHT, Valid_Cargo->getWeight() + weight));
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Train::decreaseCargo(double weight)
	{
		if (isValid() && Valid_Cargo != nullptr && Valid_Cargo->getWeight() > MIN_WEIGHT)
		{
			Valid_Cargo->setWeight(max(MIN_WEIGHT, Valid_Cargo->getWeight() - weight));
			return true;
		}
		else
		{
			return false;
		}

	}

	void Train::unloadCargo()
	{
		delete Valid_Cargo;
		Valid_Cargo = nullptr;

	}

	void Train::display() const
	{
		cout << "***Train Summary***" << endl;
		if (!isValid())
		{
			cout << "This is an invalid train." << endl;
		}
		else if (Valid_Cargo == nullptr)
		{
			cout << "    Name: " << Valid_Name << endl;
			cout << "      ID: " << Valid_ID << endl;
			cout << "No cargo on this train." << endl;
		}
		else
		{
			cout << "    Name: " << Valid_Name << endl;
			cout << "      ID: " << Valid_ID << endl;
			cout << "   Cargo: " << Valid_Cargo->getDesc() << endl;
			cout << "  Weight: " << fixed << setprecision(2) << Valid_Cargo->getWeight() << setprecision(-1) << endl;
cout.unsetf(ios_base::floatfield);
		}
	}

}