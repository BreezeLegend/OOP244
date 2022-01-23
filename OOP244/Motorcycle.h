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

#pragma once
#include "Vehicle.h"
namespace sdds {
    class Motorcycle : public Vehicle {
        bool m_sidecar;

    public:
        istream& read(istream& str = cin) override;

        ostream& write(ostream& str = cout) const override;
    };
}