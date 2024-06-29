/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Amany Omar
Email: aomar22@myseneca.ca
ID: 126 127 166
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>

using namespace std;
#include "Menu.h"
#include "Utils.h"
namespace seneca {
	Menu::Menu()
	{
	}

	Menu::Menu(char* title)
	{
	}

	Menu::~Menu()
	{
	}

	std::ostream& Menu::displayTitle(std::ostream& ti) const
	{
		// TODO: insert return statement here
	}

	std::ostream& Menu::displayMenu(std::ostream& mn) const
	{
		// TODO: insert return statement here
	}

	unsigned int Menu::run()
	{
		return 0;
	}

	Menu& Menu::operator~()
	{
		// TODO: insert return statement here
	}

	Menu& Menu::operator<<(const char* menuitemConent)
	{
		// TODO: insert return statement here
	}

	Menu::operator int()
	{
	}

	Menu::operator unsigned int()
	{
	}

	Menu::operator bool()
	{
	}

	Menu& Menu::operator<<(const char* title) const
	{
		// TODO: insert return statement here
	}

	const char* seneca::Menu::operator[](unsigned int MAX_MENU_ITEMS)
	{
		return nullptr;
	}

	MenuItem::~MenuItem()
	{
	}

	MenuItem::operator bool() const
	{
	}

	MenuItem::operator const char* ()
	{
	}

	std::ostream& MenuItem::display(std::ostream& Item) const
	{
		// TODO: insert return statement here
	}
}
