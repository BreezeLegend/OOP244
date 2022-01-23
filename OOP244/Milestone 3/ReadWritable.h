#pragma once
#include <iostream>
using namespace std;
namespace sdds
{
	class ReadWritable
	{
	private:
		bool csv;

	public:
		ReadWritable();

		bool isCsv() const;

		void setCsv(bool value);

		virtual istream& read(istream& str = cin)
		{
			return str;
		}

		virtual ostream& write(ostream& str = cout) const
		{
			return str;
		}

		friend istream& operator>>(istream& str, ReadWritable& rw);

		friend ostream& operator<<(ostream& str, const ReadWritable& rw);
	};


}