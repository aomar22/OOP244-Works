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

using namespace std;
#include "Menu.h"
#include "Utils.h"
namespace seneca {
	Menu::Menu()
	{
		m_title = nullptr;
		m_items[0] = { 0 };
		m_noOfItems = 0;
		
	}
	void Menu::setEmpty() {
		m_title = nullptr;
		m_noOfItems = 0;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			m_items[i] = nullptr;
		}
	}
	Menu::Menu(const char* title)
	{    
		setEmpty();
		if (title != nullptr && m_title) {
			//delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_title[strlen(title) + 1] = '\n';
		}
	}

	Menu::~Menu()
	{
		/*Looping through the MenuItems array of pointers,
		it deletes each pointer up to the number of menu items in the menu.*/
		delete[] m_title;
		for (auto i = 0; i < MAX_MENU_ITEMS; i++) {
			delete[] m_items[i];
		}
	}
	ostream& Menu::displayTitle(std::ostream& ti) const
	{
		if (m_title[0]!= '\0') {
			ti << m_title;
		}
		return ti;
	}
	
	ostream& Menu::displayMenu(std::ostream& mn) const
	{   
			displayTitle(mn);
			mn << ":" << std::endl;
			//int rowNum = 1;
			for (auto i = 0; i < MAX_MENU_ITEMS; i++) {
				mn.width(2);
				mn.setf(ios::right);
				mn << (i + 1);
				mn.fill('-');
				mn << ' ';
				mn << m_items[i] << std::endl;
				i--;
			}
		
		mn << "0- Exit" << '\n' << "> ";
		return mn;
	}
	
	unsigned int Menu::run() const
	{
		Utils ut;
		ostream& mn = displayMenu(mn); //displaying menu
		unsigned int userSelection;
		userSelection = ut.getInt(0, MAX_MENU_ITEMS); //foolproof function for user's Selection
		return userSelection;
	}

	Menu& Menu::operator~()
	{
		Utils ut{};
		ostream& mn = displayMenu(mn);
		unsigned int userSelection;
		userSelection = ut.getInt(0, MAX_MENU_ITEMS);
		return *this;
	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{   	
			if (m_noOfItems < MAX_MENU_ITEMS) {
				m_items[m_noOfItems] = new MenuItem(menuItemContent);
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
		return m_noOfItems >= 1;
	}
	
	Menu& Menu::operator<<(Menu& M) 
	{
		if (M.m_title != nullptr) {
			cout << "The " << M.m_title << " is not empty and has " << unsigned int() << " menu items." << endl;
		}
		
		return M;
	}
	
	const char* Menu::operator[](int index) 
	{
		for (index = 0; index < m_noOfItems; index++) {
			cout << m_items[index] << endl;
			if (index == m_noOfItems) {
				cout << m_items[index % m_noOfItems];
			}
		}	
		return m_items[index]->m_itemsContent;
	}

	MenuItem::MenuItem()
	{
		m_itemsContent[0] = '\0';
	}

	MenuItem::MenuItem(const char* str) {
		if (str[0] != '\0') {
			m_itemsContent = new char[strlen(str) + 1]; //allocate memory
			strcpy(m_itemsContent, str); //copy the incoming string
			m_itemsContent[strlen(str) + 1] = '\n'; //ensure last character is '\n'
		}
		else {
			
			m_itemsContent = nullptr;
		}
		//Allocates and sets the content of the MenuItem to a Cstring 
		// value at the moment of instantiation (or initialization)
		// If no value is provided for the description at the moment of creation, 
		// the MenuItem should be set to an empty state.
	}
	
	MenuItem::~MenuItem() {
		delete[] m_itemsContent;
	}

	MenuItem::operator bool() const //return true, if it is not empty
	{
		if (m_itemsContent[0] != '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	MenuItem::operator const char*()
	{
		return m_itemsContent; //return the address of the content Cstring to convert it to const char*
	}

	ostream& MenuItem::display(std::ostream& Item) const
	{
		if (m_itemsContent[0] != '\0'){
		   return Item << m_itemsContent;   //display the content of the MenuItem on ostream if menuItem is Not empty
		}
		else {
			m_itemsContent[0] = '\0';
		}
		return Item;
	}
}
/*Create a method to display the content of the MenuItem on ostream. (No newline is printed after)
Nothing is printed if MenuItem is empty.

	Remember that the MenuItem class is fully private.
*/