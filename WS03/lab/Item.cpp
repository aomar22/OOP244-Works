#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	const double TAX = 0.13;
	//private member functions (Methods)
	void Item::setName(const char* name) { 
		strncpy(m_itemName, name, 21);
		
		
	}

	//public member functions (Methods)
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {
		setName(name);
		m_price = price;
		m_taxed = taxed;
		if (price < 0.0 || name == nullptr) {
			setEmpty();
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
			cout.width(7);
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
		if (m_itemName[0] != '\0' || m_price != 0.0) {

			return true;
		}
		else {
			return false;
		}
	}
	double Item::price()const {

		return m_price;
	}
	double Item::tax()const {
		
	    return m_taxed ? m_price * TAX : 0.0;
	}
	

}