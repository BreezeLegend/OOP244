#pragma once
#define MAX_DESC 15
#define MAX_PRICE 999.999
namespace sdds
{
	struct Gift
	{
		char m_description[MAX_DESC + 1] = { 0 };
		double m_price;
		int m_units;
	};

	void gifting(char* desc);

	void gifting(double& price);

	void gifting(int& units);

	void display(const Gift& theGift);
}