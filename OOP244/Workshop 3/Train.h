/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 13, 2020
*/

#pragma once
#include "Cargo.h"

namespace sdds
{
const int MAX_NAME = 30;
	class Train
	{
	private:
		char Valid_Name[MAX_NAME];
		int Valid_ID;
		Cargo* Valid_Cargo;

	public:

		void initialize(const char* name, int id);

		bool isValid() const;

		void loadCargo(Cargo car);

		bool swapCargo(Train& other);

		bool increaseCargo(double weight);

		bool decreaseCargo(double weight);

		void unloadCargo();

		void display() const;

	};


}