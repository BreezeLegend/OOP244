/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 27, 2020
*/

#pragma once
#pragma once

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;
	class Engine
	{
	private:
		double m_size;
		char m_type[TYPE_MAX_SIZE];
	

	public:

		Engine();

		Engine(const char type[], double size);

		double get() const;

		void display() const;
	};


}