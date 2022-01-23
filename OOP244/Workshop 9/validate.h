/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 28, 2020
*/

#pragma once
namespace sict
{
	template < class T > 
	bool validate( const T& min, const T* values, int num, bool* output)
	{
		bool result = true;

		for (int i = 0; i < num; i++)
		{
			if (values[i] >= min)
			{
				output[i] = true;
			}
			else
			{
				output[i] = false;
				result = false;
			}
		}
		return result;
	}



}