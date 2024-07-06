#ifndef SENECA_MENU_H
#define SENECA_MENU_H
namespace seneca {
	const unsigned MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
		char* m_itemContent{ nullptr };
		friend class Menu;
		MenuItem();
		MenuItem(const char* itemContent);
		//void setEmpty();
		//rule of 3:
		//copy constructor and copy assignment are deleted
		MenuItem(MenuItem& item) = delete;
		MenuItem& operator=(MenuItem& item) = delete;
		//destructor
		~MenuItem();
		//bool type converstion
		operator bool();
		//const char* type conversion
		operator const char* ();
		//displaying the MenuItem
		std::ostream& displayMenuItem(std::ostream& ostr)const;
	};
	class Menu {
		//rule of 3:
				//copy constructor and copy assignment are deleted
		Menu(Menu& m) = delete;
		Menu& operator=(Menu& m) = delete;
		char* m_title{};
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{ nullptr };
		unsigned m_noOfItems;
		void setEmpty();
	public:
		Menu();
		Menu(const char* menuTitle);

		~Menu();
		//methods
		unsigned int run();
		bool operator~();
		Menu& operator<<(const char* menuItemContent);
		//Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
		operator int();
		operator unsigned int();
		// return true if the Menu has one or more MenuItems otherwise, false;
		operator bool();

		//Overload the insertion operator to print the title of the Menu using cout.

		//Menu& operator<<(Menu& m); // Account& operator<<(Account& acc);
		const char* operator[](unsigned index)const;
		//std::ostream& operator<<(std::ostream& om) const;
		std::ostream& displayTitle(std::ostream& om, Menu& m)const;
		std::ostream& displayAllMenu(std::ostream& om, Menu& m)const;
	};
}












#endif