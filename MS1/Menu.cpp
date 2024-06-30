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

using namespace std;
#include "Menu.h"
#include "Utils.h"
namespace seneca {
	Menu::Menu()
	{
		m_title = nullptr;
		m_items[MAX_MENU_ITEMS] = {nullptr};
		m_trackItems = 0;
	}

	Menu::Menu(const char* title)
	{
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
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
	
	
	std::ostream& Menu::displayTitle(std::ostream& ti) const
	{
		if (m_title[0]!=0) {
			ti << m_title;
		}
		return ti;
	}
	/*    This function first displays the title (if it is not empty)
	followed by a ":" and a new-line, then it will display all the MenuItems one by one;
	adding a row number in front of each. The row numbers are printed in two spaces,
	right justified followed by a "dash" and a "space". After printing all the MenuItems it should
	print " 0- Exit" and new-line and "> ".
	For example, if the title is "Lunch Menu" and the menu items are "Omelet",
	"Tuna Sandwich" and "California Rolls", the Menu object should be printed like this:

Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 >
*/
	std::ostream& Menu::displayMenu(std::ostream& mn) const
	{
		displayTitle(mn);
		mn << ":" << std::endl;
		int rowNum = 1;
		for (auto i = 0; i < MAX_MENU_ITEMS; i++) {
			mn.width(2) << mn.right << rowNum << mn.fill('-') << ' ';
			mn << m_items[i] << std::endl;
		}
		mn << "0- Exit" << '\n' << "> ";
		return mn;
	}
	/*This function displays the Menu and gets the user selection.
(this function should be completely foolproof) The function receives nothing 
and returns an unsigned integer (That is the user’s selection). 
After displaying the menu, ask for an integer and make sure the value of the integer 
is between 0 and the number of the menu items. If the user enters anything incorrect, print:
"Invalid Selection, try again: "
and get the integer again until a valid selection is made.

    Nice to do:
    The action of a foolproof integer entry within limits, with a prompt and an
	error message, is a good candidate for a separate function implementation in the Utils module
*/
	unsigned int Menu::run() 
	{
		std::ostream& mn = displayMenu(mn);
		
		unsigned int userSelection;
		userSelection = getIntMM(0, MAX_MENU_ITEMS, userSelection);

		return userSelection;
	}

	Menu& Menu::operator~()
	{
		std::ostream& mn = displayMenu(mn);
		unsigned int userSelection;
		userSelection = getIntMM(0, MAX_MENU_ITEMS, userSelection);
		return *this;
	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{
		while (m_trackItems < MAX_MENU_ITEMS) {
			char* menuItem = new char[strlen(menuItemContent) + 1];
			strcpy(menuItem, menuItemContent);
			menuItem++;
		} 
	
		return *this;
	}
	/*void Menu::silentlyIgnore() {

	}*/
	Menu::operator int()
	{
		return m_trackItems;
	}

	Menu::operator unsigned int()
	{
		return m_trackItems;
	}

	Menu::operator bool()
	{
		return m_trackItems >= 1;
	}
	
	Menu& Menu::operator<<(const char* title) 
	{
		std::cout << m_title;
		return *this;
	}
	/* return the const char* cast of the corresponding MenuItem in the array of
	MenuItem pointers. If the index passes the number of MenuItems in the Menu,
	loop back to the beginning. (use modulus)*/
	const char* Menu::operator[](unsigned int MAX_MENU_ITEMS)
	{
		Menu M;
		int index = MAX_MENU_ITEMS % m_trackItems;
		if (index != 0) {
			while (m_trackItems < MAX_MENU_ITEMS) {
				cout << M[m_trackItems]<< endl;
				m_trackItems++;
			}
		}

		return 0;
	}

	MenuItem::MenuItem(const char* str)
	{
		if (str[0] != '\n') {
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
	MenuItem::MenuItem()
	{
		m_itemsContent[0] = 0;
	}
	MenuItem::~MenuItem()
	{
		delete[] m_itemsContent;
	}

	MenuItem::operator bool() const //return true, if it is not empty
	{

		if (m_itemsContent[0] != '\n') {
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

	std::ostream& MenuItem::display(std::ostream& Item) const
	{
		if (bool()) {
			Item << m_itemsContent;   //display the content of the MenuItem on ostream if menuItem is Not empty
		}
	}
}
/*Create a method to display the content of the MenuItem on ostream. (No newline is printed after)
Nothing is printed if MenuItem is empty.

	Remember that the MenuItem class is fully private.
*/