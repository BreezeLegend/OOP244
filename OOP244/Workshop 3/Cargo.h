/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 13, 2020
*/

#pragma once
namespace sdds
{
const int MAX_DESC = 20;
const double MAX_WEIGHT = 777.555;
const double MIN_WEIGHT = 44.2222;
	class Cargo
	{
	private:
		char Valid_Desc[MAX_DESC];
		double Valid_Weight;


	public:

		void initialize(const char* desc, double weight);

		const char* getDesc() const;

		double getWeight() const;

		void setDesc(const char* description);

		void setWeight(double weight);
	};

}