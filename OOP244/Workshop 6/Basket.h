#pragma once
#include <iostream>
namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket
	{
	private:
		Fruit* m_fruits;
		int m_cnt;
		double m_price;
		
		void copyBasket(const Basket& basket);

	public:

		Basket();
		
		~Basket();

		Basket(Fruit* fruits, int size, double price);

		Basket(const Basket& basket);

		Basket& operator= (Basket basket);

		operator bool() const;

		Basket& operator+= (Fruit fruit);

		void setPrice(double price);

		friend std::ostream& operator<< (std::ostream& out, const Basket& basket);
	};

}