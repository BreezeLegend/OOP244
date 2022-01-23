/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 9, 2020
*/

#pragma once
#include "Cargo.h"
#define MAX_NAME 30
namespace sdds
{
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
	
		void unloadCargo();
	
		void display() const;

	};

	
}