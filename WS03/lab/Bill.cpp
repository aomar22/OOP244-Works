#include <iostream>
#include <cstring>
#include "Bill.h"
#include "Item.h"
using namespace std;
namespace seneca {
	// private member functions 
    double Bill::totalTax()const {
        double totalTax;
        
        return totalTax;
    }

    double Bill::totalPrice()const {

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
        if (isValid) {
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
        m_title == '\0';
        m_items == nullptr;
    }
    /*isValid: Returns true if m_title is not empty
      and m_items is not null and all the Items in the m_items array are valid.

    hint: First check and make sure m_title and m_items are valid.
    Then loop through all the Items in the m_items array and make sure they are all valid.
*/
    //while running the program try useing {} //nullptr or 0 if error
    bool Bill::isValid()const {
        bool ok = true;
        int num; //noOfItems
        
        if (m_title[0] != '\0' && m_items != nullptr) {
           
            for (int i = 0; i < num; i++) {
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

    // public member functions
    void Bill::init(const char* title, int noOfItems) {


    }

    bool Bill::add(const char* item_name, double price, bool taxed) {



    }

    void Bill::display()const {


    }

    void Bill::deallocate() {


    }

}