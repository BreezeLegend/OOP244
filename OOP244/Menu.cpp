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


#include "Menu.h"
#include <string>

namespace sdds
{
	MenuItem::MenuItem(const char* content)
	{
		if (content == nullptr)
		{
			this->content = nullptr;
		}
		else
		{
			this->content = new char[strlen(content) + 1];
			strcpy(this->content, content);
		}
	}

	std::ostream& MenuItem::print(std::ostream& stream) const
	{
		if (content != nullptr)
			stream << content << "\n";
		return stream;
	}

	MenuItem::~MenuItem()
	{
		if (content != nullptr)
			delete[] content;
	}

	Menu::Menu(const char* title, int indentation)
	{
		if (title == nullptr)
		{
			this->title = nullptr;
		}
		else
		{
			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
			this->indentation = indentation;
			this->item_cnt = 0;
		}
	}

	void Menu::copyTo(const Menu& other)
	{
		if(title != nullptr){
			delete[] title;
		}
		
		for (int i = 0; i < item_cnt; i++)
		{
			delete menu_items[i];
		}
		
		item_cnt = 0;
		if (other)
		{
			this->title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);
			item_cnt = other.item_cnt;
			indentation = other.indentation;
			for (int i = 0; i < item_cnt; i++)
			{
				menu_items[i] = new MenuItem(other.menu_items[i]->content);
			}
		}
		else
		{
			title = nullptr;
		}
	}

	Menu::Menu(const Menu& other)
	{
		copyTo(other);
	}

	Menu& Menu::operator=(const Menu& other)
	{
		copyTo(other);
		return *this;
	}

	Menu::operator bool() const
	{
		return title != nullptr;
	}

	bool Menu::isEmpty() const
	{
		return title == nullptr;
	}

	void Menu::display() const
	{
		if (this->isEmpty())
		{
			std::cout << "Invalid Menu!" << "\n";
			return;
		}
		std::string indents;
		for (int i = 0; i < indentation; i++)
		{
			indents += "    ";
		}
		std::cout << indents << title << "\n";
		if (item_cnt == 0)
		{
			std::cout << "No Items to display!" << "\n";
			return;
		}
		for (int i = 1; i <= item_cnt; i++)
		{
			std::cout << indents << i << "- ";
			menu_items[i - 1]->print();
		}
		std::cout << indents << "> ";
	}

	Menu& Menu::operator=(const char title[])
	{
		if(this->title != nullptr){
			delete[] this->title;
			
		}
		
		for (int i = 0; i < item_cnt; i++)
		{
			delete menu_items[i];
		}
		
		item_cnt = 0;

		if (title == nullptr)
		{
			this->title = nullptr;
		}
		else
		{
			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
		}
		return *this;
	}

	void Menu::add(const char* content)
	{
		if (this->isEmpty()) return;
		if (content == nullptr)
		{
			if(title != nullptr)
			{
				delete[] title;
			}	
			title = nullptr;
			return;
		}
		if (item_cnt == MAX_NO_OF_ITEMS) return;
		menu_items[item_cnt] = new MenuItem(content);
		item_cnt++;
	}

	Menu& Menu::operator<<(const char* content)
	{
		add(content);
		return *this;
	}

	int Menu::run() const
	{
		display();
		if (this->isEmpty() || item_cnt == 0) return 0;
		int choice = -1;
		while (true)
		{
			std::string input;
			std::getline(std::cin, input);
			try
			{
				choice = std::stoi(input, NULL);
				if (choice > 0 && choice <= item_cnt)
				{
					break;
				}
				std::cout << "Invalid selection, try again: ";
			}
			catch (const std::exception& e)
			{
				std::cout << "Invalid Integer, try again: ";
			}
		}
		return choice;
	}

	Menu::operator int() const
	{
		return run();
	}

	Menu::~Menu()
	{
		if (title != nullptr)
			delete[] title;
		for (int i = 0; i < item_cnt; i++)
		{
			delete menu_items[i];
		}
	}
}
