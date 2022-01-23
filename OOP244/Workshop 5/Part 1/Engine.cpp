/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 24, 2020
*/
#include <string.h>
#include <iostream>
#include "Engine.h"
using namespace std;
namespace sdds
{
	Engine::Engine(){

	}
	Engine::Engine(const char type[], double size)
	{
		strncpy(m_type, type, TYPE_MAX_SIZE);
		m_size = size;
	}
	double Engine::get() const
	{
		return m_size;
	}

	void Engine::display() const
	{
		cout << m_size << " liters - " << m_type << endl;
	}
}