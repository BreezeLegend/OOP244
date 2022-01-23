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

#include "Motorcycle.h"
#include <string>
#include <iostream>

namespace sdds {
    istream& Motorcycle::read(istream& str) {
        if (isCsv()) {
            Vehicle::read(str);
            str >> m_sidecar;
            string buf;
            getline(str, buf);
        }
        else {
            cout << "Motorcycle information entry\n";
            Vehicle::read(str);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            string in;
            do {
                getline(str, in);
                if (in == "Y" || in == "y") {
                    m_sidecar = true;
                }
                else if (in == "N" || in == "n") {
                    m_sidecar = false;
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            } while (in != "Y" && in != "N" && in != "y" && in != "n");
        }
        return str;

    }

    ostream& Motorcycle::write(ostream& str) const {
        if (isEmpty()) {
            str << "Invalid Motorcycle Object\n";
            return str;
        }
        if (isCsv()) {
            str << "M,";
        }
        else {
            str << "Vehicle type: Motorcycle\n";
        }
        Vehicle::write(str);
        if (isCsv()) {
            str << m_sidecar << "\n";
        }
        else {
            if (m_sidecar) {
                str << "With Sidecar\n";
            }
        }
        return str;
    }
}