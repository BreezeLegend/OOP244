/* Citation and Sources
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Victor Hasnat
-----------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshop assignments.
-----------------------------------------------------
*/

#include "Car.h"
#include <string>
#include <iostream>

namespace sdds {
    istream& Car::read(istream& str) {
        if (isCsv()) {
            Vehicle::read(str);
            str >> m_carwash;
            string buf;
            getline(str, buf);
        }
        else {
            cout << "Car information entry\n";
            Vehicle::read(str);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            string in;
            do {
                getline(str, in);
                if (in == "Y" || in == "y") {
                    m_carwash = true;
                }
                else if (in == "N" || in == "n") {
                    m_carwash = false;
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            } while (in != "Y" && in != "N" && in != "y" && in != "n");
        }
        return str;
        
    }

    ostream& Car::write(ostream& str) const {
        if (isEmpty()) {
            str << "Invalid Car Object\n";
            return str;
        }
        if(isCsv()) {
            str << "C,";
        }
        else {
            str << "Vehicle type: Car\n";
        }
        Vehicle::write(str);
        if (isCsv()) {
            str << m_carwash << "\n";
        }
        else {
            if (m_carwash) {
                str << "With Carwash\n";
            }
            else {
                str << "Without Carwash\n";
            }
        }
        return str;
    }
}