#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace seneca {
	// private member functions 
    
    double Bill::totalTax()const {
        double totalTax = 0.0;
        int i;
        for (i = 0; i < m_noOfItems; i++) {

            totalTax += m_items[i].Item::tax();
        }
        
        return totalTax;
    }

    double Bill::totalPrice()const {
        double totalPrice = 0.0;
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            //totalPrice = m_items[i].price() + m_items[i].tax();
            totalPrice += m_items[i].Item::price();
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
            cout << "|          Total After Tax: ";
            cout << right;
            cout.setf(ios::fixed);
            cout.width(10);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid()const {
        bool ok = true;

        if (m_title[0] != '\0' && m_items != nullptr) {
            int i;
            for (i = 0; i < m_noOfItems; i++) {
                if (m_items[i].isValid()) {
                    ok = true;
                }
                else {
                    ok = false;
                }
            }
        }
        return ok;
    }

    void Bill::init(const char* title, int noOfItems) {
      
        if (m_title == nullptr || noOfItems <= 0) {
            m_title[0] = '\0';
            noOfItems = 0;
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title, title, 36);
            m_items = nullptr;   
            m_items = new Item[m_noOfItems];  
            
        }

    }
    bool Bill::add(const char* item_name, double price, bool taxed) {  
        
         if (m_itemsAdded < m_noOfItems) {
             m_items[m_itemsAdded].Item::set(item_name, price, taxed);
             m_itemsAdded += 1 ;
             return true;
         }
          else {
             return false;
          } 
        
    }
    void Bill::display()const {
        
        Title();
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();    
        
    }
    void seneca::Bill::deallocate() {
        int i;
        for (i = 0; i < m_noOfItems; i++) {
            delete[] m_items;
            m_items = nullptr;
        }

    }
}

   
