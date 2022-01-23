/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: May 30, 2020
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Utils.h"

using namespace std;

void markstat() {
	string name;
	int number;

	cout << "Mark Stats Program." << endl << endl;
	cout << "Please enter the assessment name: ";
	getline(cin, name);
	while (name.length() > 40) {
		cout << "The assesment name was too long! Enter a new one: ";
		getline(cin, name);
	}
	cout << "Please enter the number of marks: ";
	
	number = getValueRanged(5, 50);

	cout << "Please enter " << number << " marks (0<=Mark<=100):" << endl;
	int* marks = new int[number];
	for (int i = 1; i <= number; i++) {
		cout << to_string(i) << "> ";
		marks[i - 1] = getValueRanged(0, 100);
	}
	sort(marks, marks + number, greater<int>());
	cout << "Thank you..." << endl;
	cout << "Assessment Name: " << name << endl;
	cout << "----------------" << endl;
	float av = 0;
	int passing_marks = 0;
	for (int i = 0; i < number; i++) {
		if (marks[i] >= 50) passing_marks++;
		av += marks[i];
		cout << marks[i];
		if (i != number - 1) cout << ", ";
		else cout << endl;
	}
	av /= number;
	cout << "Average: " << fixed << setprecision(1) << av << endl;
	cout << "Number of Passing Marks: " << passing_marks << endl;
}


