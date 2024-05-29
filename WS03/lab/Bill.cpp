#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace seneca {
	// private member functions 
    double totalTax()const {

    }

    double totalPrice()const {

    }

    void Title()const {

    }

    void footer()const {

    }

    void setEmpty() {

    }
    /*isValid: Returns true if m_title is not empty
      and m_items is not null and all the Items in the m_items array are valid.

    hint: First check and make sure m_title and m_items are valid.
    Then loop through all the Items in the m_items array and make sure they are all valid.
*/
    bool Bill::isValid()const {
        bool ok = true;
        if (m_title[0] != '\0' && m_items != nullptr)
        return ok;
    }

    // public member functions
    void init(const char* title, int noOfItems) {


    }

    bool add(const char* item_name, double price, bool taxed) {



    }

    void display()const {


    }

    void deallocate() {


    }

}