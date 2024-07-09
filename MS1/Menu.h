#ifndef SENECA_MENU_H
#define SENECA_MENU_H
namespace seneca {
	const unsigned MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
	private:

		char* m_itemContent{ nullptr };
		friend class Menu;
		MenuItem();
		MenuItem(const char* itemContent);
		void setEmpty();
		//rule of 3:
		//copy constructor and copy assignment are deleted
		MenuItem(MenuItem& item) = delete;
		MenuItem& operator=(MenuItem& item) = delete;
		//destructor
		~MenuItem();
		//bool type converstion
		operator bool()const;
		//const char* type conversion
		operator const char* ()const;
		//displaying the MenuItem
		//bool isMenuItemValid()const;
		std::ostream& displayMenuItem(std::ostream& os)const;
	};
	class Menu {
		//rule of 3:
				//copy constructor and copy assignment are deleted
		Menu(Menu& m) = delete;
		Menu& operator=(Menu& m) = delete;
		/*MenuItem m_title{};*/
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{ nullptr };
		unsigned int m_noOfItems;
		void setEmpty();
		bool isValid();
		//std::ostream& view(std::ostream& os = std::cout) const;
	public:
		MenuItem m_title{};
		Menu();
		Menu(const char* menuTitle);
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		~Menu();
		//methods
		Menu& operator<<(const char* menuItemContent); //simple
		
		unsigned int run() const;
		unsigned int operator~()const;
		
		//Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
		operator int()const;
		operator unsigned int()const;
		// return true if the Menu has one or more MenuItems otherwise, false;
		operator bool()const;

		//Overload the insertion operator to print the title of the Menu using cout.
	
		/*std::ostream& operator<<(std::ostream& os);*/

		//Menu& operator<<(Menu& m); // Account& operator<<(Account& acc);
		const char* operator[](unsigned index)const;
		//std::ostream& operator<<(std::ostream& om) const;

		std::ostream& displayTitle(std::ostream& om) const;
		std::ostream& displayAllMenu(std::ostream& om)const;
		/*std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);*/
	};
	std::ostream& operator<<(std::ostream& om, const Menu& m);
}












#endif