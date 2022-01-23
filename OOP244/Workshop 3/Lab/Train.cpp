/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 9, 2020
*/

#include <iostream>
#include <string.h>
#include "Train.h"
#include "Cargo.h"
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
        if (Valid_Cargo != nullptr) {
            delete Valid_Cargo;
        }
        Valid_Cargo = new Cargo;
        memcpy(Valid_Cargo, &car, sizeof(Cargo));
    }
	void Train::unloadCargo()
	{
		delete Valid_Cargo;
		Valid_Cargo = nullptr;
	}

	void Train::display() const
	{
		cout << "***Train Summary***" << endl;
		if (!isValid()){ 
			cout << "This is an invalid train." << endl;
		}
		else if (Valid_Cargo == nullptr)
		{
			cout << "Name: " << Valid_Name << endl;
			cout << "ID: " << Valid_ID << endl;
			cout << "No cargo on this train." << endl;
		}
		else
		{
			cout << "Name: " << Valid_Name << endl;
			cout << "ID: " << Valid_ID << endl;
			cout << "Cargo: " << Valid_Cargo->desc << endl;
			cout << "Weight: " << Valid_Cargo->weight << endl;
		}

	}

}
