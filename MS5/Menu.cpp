/* Citation and Sources...
Final Project Milestone 2
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
#include "Menu.h"
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
		m_itemContent = nullptr;
	}
	MenuItem::MenuItem() {
		m_itemContent = nullptr;
	}
	MenuItem::MenuItem(const char* itemContent) {
		if (itemContent) {
			m_itemContent = new char[strlen(itemContent) + 1];
			strcpy(m_itemContent, itemContent);
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
	}
	MenuItem::operator const char* ()const
	{
		return m_itemContent;
	}
	ostream& MenuItem::displayMenuItem(ostream& os) const
	{
		if (*this && m_itemContent) {
			os << m_itemContent;
		}
		return os;
	}
	Menu& Menu::operator=(Menu& m)
	{
		return *this;
	}
	void Menu::setEmpty()
	{

		m_menuItems[0] = { nullptr };
		m_noOfItems = 0;
	}
	Menu::Menu()
	{
		m_title.m_itemContent = nullptr;
		m_noOfItems = 0;
		m_menuItems[0] = { nullptr };

	}
	Menu::Menu(const char* menuTitle)
	{
		setEmpty();

		if (menuTitle != nullptr) {
			m_title.m_itemContent = new char[strlen(menuTitle) + 1];
			strcpy(m_title.m_itemContent, menuTitle);
			m_noOfItems = 0;
		}
		else {
			setEmpty();
		}
	}
	Menu::Menu(const Menu& m)
	{
	}
	Menu::~Menu()
	{
		for (unsigned i = 0; i < MAX_MENU_ITEMS; i++) {
			delete m_menuItems[i];
		}
	}
	unsigned int Menu::run() const
	{
		int selection = 0;

		displayAllMenu();
		cin >> selection;
		while (cin.fail() || selection < 0 || (unsigned int)(selection) > m_noOfItems) {
			if (cin.fail() || selection < 0 || (unsigned int)(selection) > m_noOfItems) {
				cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> selection;
			}
			else {
				cin.clear();
				cin.ignore(10000, '\n');
			}
			cin.ignore(10000, '\n');
		}
		return selection;
	}
	const char* Menu::operator[](unsigned index)const
	{
		if (index <= m_noOfItems) {
			index = index % m_noOfItems;

			return (const char*)(m_menuItems[index]->m_itemContent);
		}
		else {
			return nullptr;
		}
	}

	unsigned int Menu::operator~() const {
		return run();
	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{
		if (menuItemContent && m_noOfItems < MAX_MENU_ITEMS) {
			m_menuItems[m_noOfItems] = new MenuItem(menuItemContent);
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

	}
	const char* Menu::getMenuTitle() const {
		return m_title.m_itemContent ? m_title.m_itemContent : "";
	}
	std::ostream& Menu::displayTitle() const
	{
		const char* title = getMenuTitle();
		if (title) {
			cout << title;
		}
		return cout;
	}

	std::ostream& Menu::displayAllMenu() const
	{
		bool valid = m_title.m_itemContent != nullptr && m_menuItems != nullptr && m_noOfItems >= 1;
		if (valid) {
			displayTitle();
			//cout << ":" << endl;
			cout << endl;
		}
		unsigned i = 0;
		while (i < m_noOfItems) {
			cout.width(2);
			cout.fill(' ');
			cout << (i + 1);
			cout.setf(ios::right);
			cout << ('-');
			cout << (' ');
			cout << m_menuItems[i]->m_itemContent << endl;
			i++;
		}
		cout << " " << i % m_noOfItems << "- Exit" << '\n' << "> ";

		return cout;
	}
	std::ostream& operator<<(std::ostream& om, const Menu& m)
	{
		m.displayTitle();
		return om;
	}
}
