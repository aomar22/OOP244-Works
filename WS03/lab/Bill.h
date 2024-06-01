#ifndef SENECA_BILL_H
#define SENECA_BILL_H
#include "Item.h"
namespace seneca {
   class Bill {
      char m_title[37];   // title of the shopping list
      Item* m_items = nullptr;      //// pointer to the dynamically allocated array of Items
      int m_noOfItems;   //// size of the dynamically allocated array of Items
      int m_itemsAdded; //// number of the Items added by the add method
      /*totalTax: Adds all the taxes of the items using a loop and returns the sum.*/
      double totalTax()const;  //// returns the total tax applied to the Items
     /*totalPrice: Adds all the prices of the items using a loop and returns the sum;*/
      double totalPrice()const;  // returns the sum of prices of Items
   
      void Title()const; //// Prints the title of the shopping list

      void footer()const;  // prints the footer contaning total tax, price and total price after tax

      void setEmpty();   // sets the Bill to an emtpy state

      bool isValid()const; // returns true is the Bill and all of its Items are valid

   public:
       
      void init(const char* title, int noOfItems);

      bool add(const char* item_name, double price, bool taxed);

      void display()const;

 
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
