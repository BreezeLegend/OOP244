/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 17, 2020
*/

#pragma once
#define MAX_NAME 32
#define MAX_DOB 2020
#define MIN_POWER 0
namespace sdds
{
	class Saiyan 
	{ 
	private:
		char m_name[MAX_NAME];
		int m_dob;
		int m_power;
		bool m_super;
	public:
	
	Saiyan();

	Saiyan(const char* name, int dob, int power);

	void set(const char* name, int dob, int power, bool super = false);

	bool isValid() const;

	void display() const;

	bool fight(const Saiyan& other) const;
};
}