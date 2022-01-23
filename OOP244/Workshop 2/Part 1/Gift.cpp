#include <string.h>
#include <iostream>
#include <string>
#include "Gift.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
	
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		string input;
		getline(cin, input);  //get input
		input.resize(MAX_DESC);
		strcpy(desc, input.c_str()); //put it into char* desc

	}

	void gifting(double& price)
	{
		cout << "Enter gift price: ";
		string input;
		getline(cin, input);
		double temp = stod(input.c_str());
		while (temp > MAX_PRICE || temp < 0)
		{

			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			getline(cin, input);
			temp = stod(input.c_str());
		}
		price = temp;
	}

	void gifting(int& units)
	{
		cout << "Enter gift units: ";
		string input;
		getline(cin, input);
		int temp = stoi(input.c_str());
		while (temp < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			getline(cin, input);
			temp = stoi(input.c_str());
		}
		units = temp;
	}

	void display(const Gift& theGift)
	{
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
cout << "\n";
	}

}