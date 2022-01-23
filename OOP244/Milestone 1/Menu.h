/* Citation and Sources
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author Victor Hasnat
-----------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshop assignments.
-----------------------------------------------------
*/

#pragma once
#include <string.h>
#include <iostream>

namespace sdds
{
    constexpr int MAX_NO_OF_ITEMS = 10;

    class MenuItem
    {
        char* content;

        MenuItem(const char* content);

        MenuItem(const MenuItem&) = delete;

        std::ostream& print(std::ostream& stream = std::cout) const;

        MenuItem& operator=(const MenuItem&) = delete;

        ~MenuItem();

        friend class Menu;
    };

    class Menu
    {
        char* title = nullptr;

        MenuItem* menu_items[MAX_NO_OF_ITEMS];

        int item_cnt = 0;

        int indentation;

        void copyTo(const Menu& other);

    public:
        Menu(const char* title, int indentation = 0);

        Menu(const Menu& other);

        Menu& operator=(const Menu& other);

        operator bool() const;

        bool isEmpty() const;

        void display() const;

        Menu& operator=(const char title[]);

        void add(const char* content);

        Menu& operator<<(const char* content);

        int run() const;

        operator int() const;

        ~Menu();
    };
}