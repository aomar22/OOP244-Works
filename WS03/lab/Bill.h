#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"
namespace seneca {
   class Bill {
      char m_title[37];   // title of the shopping list
      Item* m_items;      //// pointer to the dynamically allocated array of Items
      int m_noOfItems;   //// size of the dynamically allocated array of Items
      int m_itemsAdded; //// number of the Items added by the add method
      /*totalTax: Adds all the taxes of the items using a loop and returns the sum.*/
      double totalTax()const;  //// returns the total tax applied to the Items
     /*totalPrice: Adds all the prices of the items using a loop and returns the sum;*/
      double totalPrice()const;  // returns the sum of prices of Items
     /*Title: Prints the title in the following format:

Prints: "+--------------------------------------+"<NEWLINE>

If the Bill is valid

"| "  
m_title; left-justified in 36 spaces
" |"  
Newline

If the Bill is invalid

"| Invalid Bill                         |"<NEWLINE>

Then in both cases (valid or invalid), it will print:

"+----------------------+---------+-----+"<NEWLIN>
"| Item Name            | Price   + Tax |"<NEWLIN>
"+----------------------+---------+-----+"<NEWLIN>
*/
      void Title()const; //// Prints the title of the shopping list

      void footer()const;  // prints the footer contaning total tax, price and total price after tax

     /*setEmpty: by setting m_title to an Empty Cstring and m_items to nullptr*/
      void setEmpty();   // sets the Bill to an emtpy state

      /*isValid: Returns true if m_title is not empty 
      and m_items is not null and all the Items in the m_items array are valid.

    hint: First check and make sure m_title and m_items are valid.
    Then loop through all the Items in the m_items array and make sure they are all valid.
*/
      bool isValid()const; // returns true is the Bill and all of its Items are valid
   public:
       /*init: If any of the arguments are invalid, it will set the Bill 
       to an empty state (ie. title is null or noOfItems is zero or less)

        Otherwise, if the incoming arguments are valid:

       init() function will first set the m_noOfItems member variable to the incoming 
       corresponding argument and sets m_itemsAdded to zero.
       Next, it will copy the Cstring pointed by the title argument into m_title attribute up to 36 characters
       Then it will dynamically allocate an array of Items pointed by m_items member variable.
       The length of this array will be m_noOfItems.

       Make sure all the dynamically allocated Items are set to empty
*/
      void init(const char* title, int noOfItems);

      /*add: If the number of added Items (m_itemsAdded) is less than
      the length of the m_items array, this function will set the next available subject
      to the incoming argument values. Then it will add one to the m_itemsAdded and return true;

      Otherwise, this function will do nothing, returning false;*/
      bool add(const char* item_name, double price, bool taxed);

      /*display: This function will first print the title(), then it will loop 
      through the m_items elements, printing every one of them, and finally prints the footer(). 
      This function can not modify the Bill.*/
      void display()const;

      /*deallocate: Deallocates the m_items arrays and sets the pointers to null.*/
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
