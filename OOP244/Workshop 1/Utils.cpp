/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: May 30, 2020
*/
#include <string>
#include <iostream>

using namespace std;

int getValueRanged(int min, int max) {
	string number_unparsed;
	int number;
	bool works = false;
	while (!works) {
		getline(cin, number_unparsed);
		bool breaked = false;
		bool starts_with_num = false;
		for (char c : number_unparsed) {
			if (c >= '0' && c <= '9') {
				starts_with_num = true;
			}
			else {
				if (starts_with_num) {
					cout << "Invalid trailing characters, try again: ";
				}
				else {
					cout << "Invalid Number, try again: ";
				}
				breaked = true;
				break;
			}
		}
		if (!breaked) {
			number = stoi(number_unparsed.c_str());
			if (number >= min && number <= max) works = true;
			else {
				cout << "Invalid value (" << min << "<=value<=" << max << "), try again: ";
			}
		}
	}
	return number;
}