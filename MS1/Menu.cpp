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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace seneca {
	/*void MenuItem::setEmpty() {
		if (m_itemContent != nullptr) {
			delete[] m_itemContent;
			m_itemContent = nullptr;
		}
	}*/
	MenuItem::~MenuItem()
	{
		delete[] m_itemContent;
	}
	MenuItem::MenuItem() {
		m_itemContent = nullptr;
	}
	MenuItem::MenuItem(const char* itemContent) {

		if (itemContent) {
			delete[] m_itemContent;
			m_itemContent = new char[strlen(itemContent) + 1];
			strcpy(m_itemContent, itemContent);

		}
		else {
			itemContent = nullptr;
		}
	}
	MenuItem::operator bool()
	{
		//When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.
		if (m_itemContent != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	MenuItem::operator const char* ()
	{
		//When a MenuItem is casted to “const char*” it should return the address of the content Cstring.
		return m_itemContent;
	}
	std::ostream& MenuItem::displayMenuItem(std::ostream& ostr) const
	{

		if (m_itemContent != nullptr) {
			ostr << m_itemContent;
		}

		return ostr;
	}
	void Menu::setEmpty()
	{
		m_title = nullptr;
		m_menuItems[0] = { nullptr };
		m_noOfItems = 0;
	}
	Menu::Menu()
	{
		setEmpty();
	}
	Menu::Menu(const char* menuTitle)
	{
		setEmpty();
		if (menuTitle) {
			delete[] m_title;
			m_title = new char[strlen(menuTitle) + 1];
			strcpy(m_title, menuTitle);
		}
	}


	Menu::~Menu()
	{
		delete[] m_title;
		m_title = nullptr;

		for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
			delete[] m_menuItems[i];
		}
	}

	unsigned int Menu::run()
	{
		Utils ut;
		unsigned userSelection;
		Menu m;
		ostream& mn2 = std::cout;
		m.displayAllMenu(mn2, m);
		userSelection = ut.getInt(0, MAX_MENU_ITEMS);
		/*while (userSelection < 0 || userSelection > MAX_MENU_ITEMS ) {
			cout << "Invalid Selection, try again: ";
			cout << ">>>>>Enter";
		}*/
		return userSelection;
	}
	const char* Menu::operator[](unsigned index)const
	{
		if (index < m_noOfItems) {
			index = index % m_noOfItems;

			return m_menuItems[index]->m_itemContent;
		}
		else {
			return nullptr;
		}
	}

	bool Menu::operator~() {
		Menu m;
		return m.run();
	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{
		MenuItem m;
		//string menuItem;
		unsigned count = 0;
		if (m_noOfItems < MAX_MENU_ITEMS) {
			m_menuItems[count] = new MenuItem[MAX_MENU_ITEMS];

			if (menuItemContent) {
				m.m_itemContent = new char[strlen(menuItemContent) + 1];
				strcpy(m.m_itemContent, menuItemContent);
				m_menuItems[count]++;
			}
		}
		return *this;
	}

	Menu::operator int()
	{
		return m_noOfItems;
	}

	Menu::operator unsigned int()
	{
		return m_noOfItems;
	}

	Menu::operator bool()
	{
		if (m_noOfItems >= 1) {
			return true;
		}
		else {
			return false;
		}
	}

	//std::ostream& Menu::operator<<(std::ostream& om) const
	//{
	//	if (m_title) {
	//		//m_title = m.m_title;
	//		cout << m_title << endl;
	//	}
	//	return om;
	//}

	std::ostream& Menu::displayTitle(std::ostream& om, Menu& m) const
	{
		if (m.m_title != nullptr) {
			om << m.m_title << endl;
		}
		return om;
	}
	std::ostream& Menu::displayAllMenu(std::ostream& om, Menu& m) const
	{
		if (m_title != nullptr) {
			m.displayTitle(om, m);
			om << ":" << endl;
			for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
				om.width(2);
				om.setf(ios::right);
				om << (i + 1);
				om.fill('-');
				om << ' ';
				om << m.m_menuItems[i] << endl;
				i--;
			}
			om << "0- Exit" << '\n' << "> ";
		}
		return om;
	}
}
