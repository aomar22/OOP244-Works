#ifndef SENECA_BILL_H
/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 1st, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/

#define SENECA_BILL_H
#include "Item.h"
namespace seneca {
   class Bill {
      char m_title[37];   
      Item* m_items = nullptr;      
      int m_noOfItems;   
      int m_itemsAdded; 
      double totalTax()const;
      double totalPrice()const;  
      void Title()const;
      void footer()const;  
      void setEmpty();   
      bool isValid()const; 
   public:  
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
