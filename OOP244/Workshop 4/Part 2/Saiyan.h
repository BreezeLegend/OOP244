/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 21, 2020
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
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;
	public:
	
	Saiyan();

	~Saiyan();

	Saiyan(const char* name, int dob, int power);

	void set(const char* name, int dob, int power,int level = 0, bool super = false);

	bool isValid() const;

	void display() const;

	bool fight( Saiyan& other);
};
}