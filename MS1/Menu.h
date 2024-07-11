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
		MenuItem(MenuItem& item) = delete;
		MenuItem& operator=(MenuItem& item) = delete;
		~MenuItem();
		operator bool()const;
		operator const char* ()const;
		std::ostream& displayMenuItem(std::ostream& os)const;
	};
	class Menu {
		Menu(Menu& m) = delete;
		Menu& operator=(Menu& m) = delete;
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{ nullptr };
		unsigned int m_noOfItems;
		void setEmpty();
	public:
		MenuItem m_title{};
		Menu();
		Menu(const char* menuTitle);
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		~Menu();
		Menu& operator<<(const char* menuItemContent); 
		unsigned int run() const;
		unsigned int operator~()const;
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](unsigned index)const;
		std::ostream& displayTitle() const;
		std::ostream& displayAllMenu()const;
		const char* getMenuTitle() const;
	};
	std::ostream& operator<<(std::ostream& om, const Menu& m);
}












#endif