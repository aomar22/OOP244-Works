#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;
namespace seneca {
	
	//private member functions (Methods) 
	void Item::setName(const char* name) { 
		int i;
		name = " ";
		strcpy(m_itemName, name);
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
		if (price <= 0.0 || name == nullptr) {
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
			cout.setf(ios::fixed);
			cout.width(7);
			cout.precision(2);
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
		/*return m_itemName[0] != NULL || m_price != 0.0;*/
		return m_itemName[0];
	}
	double Item::price()const {

		return m_price;
	}
	double Item::tax()const {
		const double TAX = 0.13;
	    return m_taxed ? m_price * TAX : 0.0;
	}
	

}