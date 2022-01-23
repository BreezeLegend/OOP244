/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 13, 2020
*/
#include <string.h>
#include <iostream>
#include "Cargo.h"
#define _CRT_SECURE_NO_WARNINGS
namespace sdds
{
	void Cargo::initialize(const char* desc, double weight)
	{
		setDesc(desc);
		setWeight(weight);
	}

	const char* Cargo::getDesc() const
	{
		return Valid_Desc;
	}

	double Cargo::getWeight() const
	{
		return Valid_Weight;
	}

	void Cargo::setDesc(const char* description)
	{
		strcpy(Valid_Desc, description);
	}

	void Cargo::setWeight(double weight)
	{
		if (weight < MIN_WEIGHT || weight > MAX_WEIGHT)
		{
			Valid_Weight = MIN_WEIGHT;
		}
		else
		{
			Valid_Weight = weight;
		}

	}

}