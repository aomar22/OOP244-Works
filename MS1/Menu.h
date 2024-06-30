/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
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
#ifndef MENU_H
#define MENU_H
#include <iostream>

namespace seneca {
	//const int stringLength = 100;
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu {
		//Rule of Three
		//Copy constructor and Copy assignment are deleted
	private:
		char* m_title; // holds the title of the Menu
		MenuItem* m_items[MAX_MENU_ITEMS]; /*Each individual element of this array
		will hold the address of a dynamically allocated MenuItem as they are added to the Menu.
		(See insertion operator overload for Menu)
Initialize this array of pointers to nullptrs.*/
		int m_trackItems; //track of how many MenuItem pointers are pointing to dynamic MenuItem objects.
		//the value of this variable is always between 0 and MAX_MENU_ITEMS.

	public:
		//Constructors:
		Menu();
		Menu(const char* title);

		//Destructor:
		~Menu();

		//Methods:
		std::ostream& displayTitle(std::ostream& ti)const;  //display the title
		std::ostream& displayMenu(std::ostream& mn)const; //display the full menu
		unsigned int run();

		//overload operators:
		Menu& operator~();
		Menu& operator<<(const char* menuItemContent);
		//type conversion:
		operator int();  // return the number of MenuItems on the Menu
		operator unsigned int(); // return the number of MenuItems on the Menu
		operator bool();      //return true if the Menu has one or more MenuItems otherwise, false;

		//overload insertion operator:
		Menu& operator<<(const char* title); //print the title of the Menu using **cout**.

		//Overload the indexing operator:
		const char* operator[](unsigned int MAX_MENU_ITEMS); 
		//return the const char* cast of the corresponding MenuItem in the array
		//of MenuItem pointers.
		//If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)
		//void silentlyIgnore();
	};
	class MenuItem {
	private:
		char* m_itemsContent; //// Dynamically allocated C-style string for menu item content
		friend class Menu;
		//constructor:
		MenuItem();
		MenuItem(const char* str);
		//*(Copy constructor and Copy assignment are deleted)*
		//Destructor:
		~MenuItem();

		//### `bool` type conversion
		operator bool()const;

		//### `const char*` type conversion
		operator const char*();
		// displaying the MenuItem
		std::ostream& display(std::ostream& Item)const;





	};

	
}

#endif  //MENU_H