/*
Name: Victor Hasnat
Email:vhasnat@myseneca.ca
Student #: 119485183
Date: July 8, 2020
*/
#include <string.h>
#include <iostream>
#include <iomanip>
#include "Basket.h"
using namespace std;
namespace sdds
{
	Basket::Basket()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	Basket::~Basket()
	{
		if (m_fruits != nullptr)
			delete[] m_fruits;
	}

	Basket::Basket(Fruit* fruits, int size, double price)
	{
		
		if (fruits != nullptr && size > 0 && price > 0)
		{
			m_fruits = new Fruit[size];
			memcpy(m_fruits, fruits, size * sizeof(Fruit));
			m_cnt = size;
			m_price = price;

		}
		else
		{
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
	}

	Basket::Basket(const Basket& basket)
	{
		copyBasket(basket);
	}

	void Basket::copyBasket(const Basket& basket)
	{
		if (basket.m_fruits != nullptr)
		{
			m_fruits = new Fruit[basket.m_cnt];
			memcpy(m_fruits, basket.m_fruits, basket.m_cnt * sizeof(Fruit));
			m_cnt = basket.m_cnt;
			m_price = basket.m_price;
		}
		else
		{
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
	}

	Basket& Basket::operator= (Basket basket)
	{
		if (m_fruits != nullptr)
		{
			delete[] m_fruits;
		}
		copyBasket(basket);
		return *this;
	}

	Basket::operator bool() const
	{
		return m_cnt > 0;
	}

	Basket& Basket::operator+= (Fruit fruit)
	{

		Fruit* new_fruits = new Fruit[m_cnt + 1];
		memcpy(new_fruits, m_fruits, m_cnt * sizeof(Fruit));
		delete[] m_fruits;
		new_fruits[m_cnt] = fruit;
		m_fruits = new_fruits;
		m_cnt++;
		return *this;
	}

	void Basket::setPrice(double price)
	{
		m_price = price;
	}

	ostream& operator<< (ostream& out, const Basket& basket)
	{
		if (!basket)
		{
			out << "The basket is empty!" << endl;
			return out;
		}
		else
		{
			out << "Basket Content:" << endl;
			for (int i = 0; i < basket.m_cnt; i++)
			{
				out << right << setw(10) << basket.m_fruits[i].m_name << ": " << fixed << setprecision(2) << basket.m_fruits[i].m_qty << "kg" << endl;
			}
			out << "Price: " << basket.m_price << endl;
			return out;
		}
	}
}