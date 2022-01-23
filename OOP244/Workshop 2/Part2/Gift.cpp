/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: June 5, 2020
*/

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
		getline(cin, input);  // get input
		input.resize(MAX_DESC);
		strcpy(desc, input.c_str()); // put it into char* desc

	}

	void gifting(double& price)
	{
		cout << "Enter gift price: ";
		string input;
		getline(cin, input); // get input
		double temp = stod(input.c_str());
		while (temp > MAX_PRICE || temp < 0) // conditions
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
		getline(cin, input); // get input
		int temp = stoi(input.c_str());
		while (temp < 1) // conditions
		{
			cout << "Gift units must be at least 1 " << endl;
			cout << "Enter gift units: ";
			getline(cin, input);
			temp = stoi(input.c_str());
		}
		units = temp;
	}
	bool wrap(Gift& theGift) {
		if (theGift.m_wrap != NULL)
		{
			cout << "Gift is already wrapped!" << endl;
			return false;
		}
		cout << "Wrapping gifts..." << endl;
		cout << "Enter the number of wrapping layers for the Gift: ";
		string input;
		getline(cin, input);
		int temp = stoi(input.c_str());
		while (temp < 1)
		{
			cout << "Layers at minimum must be 1, try again." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			getline(cin, input);
			temp = stoi(input.c_str());
			
		}
		theGift.m_wrapLayers = temp;
		theGift.m_wrap = new Wrapping[temp];
		for (int i = 0; i < temp; i++)
		{
			cout << "Enter wrapping pattern #" << i + 1 << ": " ;
			getline(cin, input);
			theGift.m_wrap[i].m_pattern = new char[input.length() + 1];
			strcpy(theGift.m_wrap[i].m_pattern, input.c_str());\
				
		}
		return true;
	}

	bool unwrap(Gift& theGift)
	{
		if(theGift.m_wrap == NULL){ 
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			return false;
       }
		cout << "Gift being unwrapped." << endl;
		for (int i = 0; i < theGift.m_wrapLayers; i++)
		{
			delete[] theGift.m_wrap[i].m_pattern;
		}
		delete[] theGift.m_wrap;
		theGift.m_wrap = NULL;
		return true;
	}
	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap (theGift);
	}

	void display(const Gift& theGift)
	{
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
		if (theGift.m_wrap == NULL)
		{
			cout << "Unwrapped!" << endl;
		}
		else
		{
			cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
			}
			 
		}
		
	}

}