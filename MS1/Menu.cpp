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
	void MenuItem::setEmpty() {
		if (m_itemContent != nullptr) {
			delete[] m_itemContent;
			m_itemContent = nullptr;
		}
	}
	MenuItem::~MenuItem()
	{
		delete[] m_itemContent;
	}
	MenuItem::MenuItem() {
		setEmpty();
	}
	MenuItem::MenuItem(const char* itemContent) {

		if (itemContent) {
			
			m_itemContent = new char[strlen(itemContent) + 1];
			strcpy(m_itemContent, itemContent);

		}
		else {
			//m_itemContent = nullptr;
			setEmpty();
		}
	}
	MenuItem::operator bool()const
	{
		if (m_itemContent) {
			return true;
		}
		else {
			return false;
		}
		
		//When a MenuItem is casted to “bool” it should return true,
		// if it is not empty and it should return false if it is empty.
		
	}
	MenuItem::operator const char* ()const
	{
		
			//When a MenuItem is casted to “const char*” it should return the address of the content Cstring.
			return m_itemContent;
		
	}
	//bool MenuItem::isMenuItemValid() const
	//{
	//	Menu m;
	//	//MenuItem* title;
	//	
	//	if (m_itemContent) {
	//		return (m_title.m_itemContent != nullptr);
	//	}
	//	
	//}
	
	ostream& MenuItem::displayMenuItem(ostream& os) const
	{//    bool valid = m_filename != nullptr && m_noOfLines > 0 && m_textLines != nullptr;

	
		if (*this && m_itemContent) {
			os << m_itemContent;
		}

		return os;
	}
	void Menu::setEmpty()
	{
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
		m_title.m_itemContent = new char[strlen(menuTitle)+1];
			strcpy(m_title.m_itemContent, menuTitle);
			m_noOfItems = 0;
		}
	}


	Menu::~Menu()
	{
		for (unsigned i = 0; i < m_noOfItems; i++) {
			delete m_menuItems[i];
		}
	}

	unsigned int Menu::run() const
	{
		
		Utils ut;
	   unsigned int userSelection;
		//Menu m;
		ostream& mn2 = cout;
		displayAllMenu(mn2);
		userSelection = ut.getInt(0, MAX_MENU_ITEMS);
		/*while (userSelection < 0 || userSelection > MAX_MENU_ITEMS ) {
			cout << "Invalid Selection, try again: ";
			cout << ">>>>>Enter";
		}*/
		return userSelection;
	}
	bool Menu::isValid() {
		if (m_title) {
			return true;
		}
		else {
			return false;
		}

	}
	
	const char* Menu::operator[](unsigned index)const
	{
		if (index <= m_noOfItems) {
			index = index % m_noOfItems;

			return m_menuItems[index]->m_itemContent;
		}
		else {
			return nullptr;
		}
	}

	unsigned int Menu::operator~() const{
		
		return run();
	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{
		//MenuItem m;
		////string menuItem;
		//unsigned count = 0;
		if (m_noOfItems < MAX_MENU_ITEMS) {
			m_menuItems[m_noOfItems] = new MenuItem(menuItemContent);

			/*if (menuItemContent) {
				m.m_itemContent = new char[strlen(menuItemContent) + 1];
				strcpy(m.m_itemContent, menuItemContent);
				m_menuItems[count]++;
			}*/
			m_noOfItems++;
		}
		return *this;
	}

	

	Menu::operator int() const
	{
		return m_noOfItems;
	}

	Menu::operator unsigned int() const
	{
		return m_noOfItems;
	}

	Menu::operator bool()const
	{
		return m_noOfItems >= 1;
		/*if (m_noOfItems >= 1) {
			return true;
		}
		else {
			return false;
		}*/
	}

	ostream& Menu::displayTitle(ostream& om) const
	{
		if (m_title.m_itemContent != nullptr) {
			om << m_title.m_itemContent << endl;
		}
		return om;
	}
	ostream& Menu::displayAllMenu(ostream& om) const
	{
		bool valid = m_title.m_itemContent != nullptr && m_menuItems != nullptr && m_noOfItems >= 1;
		if (valid) {
			displayTitle(om);
			om << ":" << endl;
			for (unsigned i = 0; i < m_noOfItems; i++) {
				om.width(2);
				om.setf(ios::right);
				om << (i + 1);
				om.fill('-');
				om << ' ';
				om << m_menuItems[i]->m_itemContent << endl;
				i--;
			}
			om << "0- Exit" << '\n' << "> ";
		}
		return om;
	}
	ostream& operator<<(ostream& om, const Menu& m)
	{
		m.displayTitle(om);

		return om;
	}
}
