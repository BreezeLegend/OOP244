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
#include "ReadWritable.h"
namespace sdds
{
    class Vehicle : public ReadWritable
    {
        char m_plate[9];
        char* m_model;
        int m_parkingnum;

    protected:
        void setEmpty();

        bool isEmpty() const;

        const char* getLicensePlate() const;

        const char* getMakeModel() const;

        void setMakeModel(const char* model);

    public:
        Vehicle();

        Vehicle(const char plate[], const char* model);

        Vehicle(const Vehicle&) = delete;

        Vehicle& operator=(const Vehicle&) = delete;

        ~Vehicle();

        int getParkingSpot() const;

        void setParkingSpot(int spot);

        friend bool operator==(const Vehicle& first, const char* plate);

        friend bool operator==(const Vehicle& first, const Vehicle& other);

        istream& read(istream& str = cin) override;

        ostream& write(ostream& str = cout) const override;

    };
}