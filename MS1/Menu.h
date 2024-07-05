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
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;      //forward declaration of Menu class
	class MenuItem {
		char* m_itemsContent{ nullptr }; //// Dynamically allocated C-style string for menu item content
		friend class Menu;
		//constructor:
		
		MenuItem();
		//*(Copy constructor and Copy assignment are deleted)*
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		//Destructor:
		~MenuItem();

		//### `bool` type conversion
		operator bool()const;

		//### `const char*` type conversion
		operator const char*();
		// displaying the MenuItem
	
	};
	class Menu {
		
	private:
		char* m_title{}; // holds the title of the Menu
		MenuItem* m_items[MAX_MENU_ITEMS]{ nullptr }; /*Each individual element of this array
		will hold the address of a dynamically allocated MenuItem as they are added to the Menu.
		(See insertion operator overload for Menu)
Initialize this array of pointers to nullptrs.*/
		unsigned int m_noOfItems; //track of how many MenuItem pointers are pointing to dynamic MenuItem objects.
		//Rule of Three
		//Copy constructor and Copy assignment are deleted
		void setEmpty();
		
		std::ostream& display(std::ostream& Item)const;
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		//the value of this variable is always between 0 and MAX_MENU_ITEMS.
		
		//std::ostream& displayTitle(std::ostream& ti) const;  //display the title
	public:
		Menu();
		std::ostream& displayTitle(std::ostream& ti, Menu& m)const;
		std::ostream& displayMenu(std::ostream& mn, Menu& m); //display the full menu

		//Constructors:
		
		Menu(const char* title);
		//Destructor:
		~Menu();

		//Methods:
		//friend std::ostream& displayTitle(std::ostream& ti, const Menu& t);  //display the title
		//friend std::ostream& displayMenu(std::ostream& mn, const Menu& m); //display the full menu
		unsigned int run()const;

		//overload operators:
		bool operator~();
		Menu& operator<<(const char* menuItemContent);
		//type conversion:
		operator int();  // return the number of MenuItems on the Menu
		operator unsigned int(); // return the number of MenuItems on the Menu
		operator bool();      //return true if the Menu has one or more MenuItems otherwise, false;

		//overload insertion operator:
		const char* operator<<(Menu& M); //print the title of the Menu using **cout**.

		//Overload the indexing operator:
		const char* operator[](unsigned index)const;
		//return the const char* cast of the corresponding MenuItem in the array
		//of MenuItem pointers.
		//If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)

	};
 //display the title
}

#endif  //MENU_H