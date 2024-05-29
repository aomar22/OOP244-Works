#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {
	const double TAX = 0.13;
	//private member functions (Methods)
	void Item::setName(const char* name) {
		char* ptr_itemName = nullptr;
		ptr_itemName = new char[strlen(name) + 1];
		if (ptr_itemName) {
			strcpy(ptr_itemName, name);
		}
		else {
			delete[] ptr_itemName;
			ptr_itemName = nullptr;
		}
	}

	//public member functions (Methods)
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {
		
		if (price < 0.0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(m_itemName);
			price = m_price;
			taxed = m_taxed;
		}
	}

	void Item::display()const {
		if (isValid()) {
			cout << "| ";
			cout << left;
			cout.width(20);
			cout.fill('.');
			cout << m_itemName;
			cout << " | ";
			cout << right;
			cout.width(7.2);
			cout.fill(' ');
			cout << m_price;
			cout << " | ";
			cout << (m_taxed ? "Yes" : "No ");
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
	bool Item::isValid()const {
		  bool ok = true;
		  if (!setEmpty) {
			  ok = false;
		  }
		  else {
			  ok = true;
		  }
		  return ok;
	}
	double Item::price()const {
		return m_price;
	}
	double Item::tax()const {
		const double tax = 0.13;
		return m_taxed ? m_price * TAX : 0.0;
	}
	

}