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

namespace seneca {
	Menu::Menu()
	{
		m_title = nullptr;
		m_items[0] = nullptr;
		m_noOfItems = 0;
		
	}
	void Menu::setEmpty() {
		m_title = nullptr;
		m_noOfItems = 0;
		m_items[0] = nullptr;
		for (auto i = 0; i < m_noOfItems; i++) {
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
		for (auto i = 0; i < m_noOfItems; i++) {
			delete[] m_items[i];
		}
	}
	std::ostream& Menu::displayTitle(std::ostream& ti) const
	{
		//if (t.m_title[0]!= '\0') {
			return ti << m_title;
		//}
		//return ti;
	}

	std::ostream& Menu::displayMenu(std::ostream& mn, Menu& m)
	{
		
			m.displayTitle(mn);
			mn << ":" << endl;
			//int rowNum = 1;
			for (auto i = 0; i < m.m_noOfItems; i++) {
				mn.width(2);
				mn.setf(ios::right);
				mn << (i + 1);
				mn.fill('-');
				mn << ' ';
				mn << m.m_items[i] << endl;
				i--;
			}
		
		mn << "0- Exit" << '\n' << "> ";
		return mn;
	}
	
	unsigned int Menu::run() const
	{
		Utils ut{};
		Menu m;
		unsigned int num;
	    ostream& mn2 = std::cout;
		m.displayMenu(mn2, m); //displaying menu
		num = ut.getInt(0, MAX_MENU_ITEMS); //foolproof function for user's Selection
		return num;
	}

	 bool Menu::operator~()
	 {
		
		if (bool()){
			run();
		}
		return true;
	 }

	 Menu& Menu::operator<<(const char* menuItemContent)
	{   	//check if the next spot for a MenuItem is available in the array of MenuItem pointers.
			if (unsigned int(m_noOfItems) < MAX_MENU_ITEMS && menuItemContent[0] != '\0') {
				//If it is, dynamically create a MenuItem out of the content received through the operator argument 
				m_items[m_noOfItems] = new MenuItem(menuItemContent);
				// store the address in the available spot 

				//increase the number of allocated MenuItem pointers by one
				m_items[m_noOfItems++];
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
		if (M && M.m_title[0] != '\0') {
			m_title = M.m_title;
				std::cout << M.m_title << std::endl;
			
		}
		
		return *this;
	}
	
	const char* Menu::operator[](int index) const
	{
		if (index >= 0 && index < m_noOfItems) {
			std::cout << m_items[index] << std::endl;
		}else if (index == m_noOfItems) {
			std::cout << m_items[index % m_noOfItems];
			//index -= m_noOfItems;
		}
		return m_items[index].m_itemsContent;
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