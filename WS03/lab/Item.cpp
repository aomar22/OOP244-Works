/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 1st, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;
namespace seneca {
	
	//private member functions (Methods) 
	void Item::setName(const char* name) { 
		
	     strnCpy(m_itemName, name, 20);
		
	}

	//public member functions (Methods)
	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = {};
		m_taxed = 0.0;
	}

	void Item::set(const char* name, double price, bool taxed) {
		
		
		if (price > 0 && name) {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		else {
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
		return m_itemName[0];
	}
	double Item::price()const {

		return m_price;
	}
	double Item::tax()const {
		const double TAX = 0.13;
		return m_taxed ? m_price * TAX : 0.0;
	}
	void Item::strnCpy(char des[], const char src[], int len) {
		int i;
		for (i = 0; i < len && src[i]; i++) {
			des[i] = src[i];
		}
		des[i] = 0;
	}
}