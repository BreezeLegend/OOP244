#include "ReadWritable.h"
#include <iostream>
using namespace std;
namespace sdds
{ 

	ReadWritable::ReadWritable()
	{
		csv = false;
	}

	bool ReadWritable::isCsv() const
	{
		return csv;
	}

	void ReadWritable::setCsv(bool value)
	{
		csv = value;
	}

	istream& operator>>(istream& str, ReadWritable& rw)
	{
		return rw.read(str);
	}

	ostream& operator<<(ostream& str, const ReadWritable& rw)
	{
		return rw.write(str);
	}

}