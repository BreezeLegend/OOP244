/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 5, 2020
*/
#ifndef _GIFT_H
#define _GIFT_H
namespace sdds
{
const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;
	struct Wrapping
	{
		char* m_pattern;
	};
		
		struct Gift
	{
		char m_description[MAX_DESC + 1] = { 0 };
		double m_price;
		int m_units;
		Wrapping* m_wrap = nullptr;
		int m_wrapLayers;
	};

	void gifting(char* desc);

	void gifting(double& price);

	void gifting(int& units);

	bool wrap(Gift& theGift);

	bool unwrap(Gift& theGift);
	
	void gifting(Gift& theGift);
	
	void display(const Gift& theGift);
}
#endif