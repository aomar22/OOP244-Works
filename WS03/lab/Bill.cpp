/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 1st, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace seneca {
	// private member functions 
    void Bill::init(const char* title, int noOfItems) {
        
        if (title == nullptr || noOfItems <= 0) {
            m_title[0] = {};
            noOfItems = 0;
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title, title, 36);
            m_items = nullptr;
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++){
            m_items[i].setEmpty();
            }
        }

    }
    bool Bill::add(const char* item_name, double price, bool taxed) {

        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded ++;
            return true;
        }
         return false;
    }
    void Bill::setEmpty() {
        m_title[0] = {};
        m_items = nullptr;
    }
    double Bill::totalTax()const {
        double totalTax = 0.0;
        int i;
        for (i = 0; i < m_noOfItems; i++) {

            totalTax += m_items[i].tax();
        }
        return totalTax;
    }

    double Bill::totalPrice()const {
        double totalPrice = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout << left;
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;

    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout << right;
            cout.setf(ios::fixed);
            cout.width(10);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;
            cout << "|              Total Price: ";
            cout << right;
            cout.width(10);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalPrice() <<  " |" << endl;
            cout << "|          Total After Tax: ";
            cout << right;
            cout.setf(ios::fixed);
            cout.width(10);
            cout.precision(2);
            cout << (totalTax() + totalPrice());
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    bool Bill::isValid()const {
        if (m_title[0] != '\0' && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems; i++) {
                if (!m_items[i].isValid()) {
                    return false;   //false if statement of if is wrong
                }
            }
            return true;  //true if statement of the 1st if is true
        }
        return false;  //false otherwise
    }

    void Bill::display()const {
        
        Title();
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();    
        
    }
    void Bill::deallocate() {
            delete[] m_items;
            m_items = nullptr;
    }
}

   
