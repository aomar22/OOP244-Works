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
        for (int i = 0; i < m_noOfItems; i++) {

            totalTax += totalTax;
        }
        return totalTax;
    }

    double Bill::totalPrice()const {
        double totalPrice = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            totalPrice = m_items[i].price() + m_items[i].tax();
            totalPrice += totalPrice;
        }
        return totalPrice;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (m_title[0] != '\0' && m_items != nullptr) {
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
           
            for (int i = 0; i < m_noOfItems; i++) {
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
      
        if (m_title[0] == '\0' && noOfItems <= 0) {
            setEmpty();   
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title, title, 36);
            m_items = nullptr;
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i] = {};
            }
        }

    }
    /*add: If the number of added Items (m_itemsAdded) is less than
    the length of the m_items array, this function will set the next available subject
    to the incoming argument values. Then it will add one to the m_itemsAdded and return true;

    Otherwise, this function will do nothing, returning false;*/
    bool Bill::add(const char* item_name, double price, bool taxed) {  
        
         if (m_itemsAdded < m_noOfItems) {
             m_items[m_itemsAdded].set(item_name, price, taxed);
             m_itemsAdded ++;
             return true;
         }
          else {
             return false;
          } 
        
    }
    /*display: This function will first print the title(), then it will loop
      through the m_items elements, printing every one of them, and finally prints the footer().
      This function can not modify the Bill.*/
    void Bill::display()const {
        
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();    
        
    }
    void seneca::Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}

   
