/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 1st, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/

#ifndef SENECA_ITEM_H
#define SENECA_ITEM_H


namespace seneca {
   class Item {
       //(attributes)
      char m_itemName[21];  
      double m_price;       
      bool m_taxed;       
      //(Methods)
      void setName(const char* name);
      
   public:
     
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
      void strnCpy(char des[], const char src[], int len);
   };
}

#endif // !SENECA_SUBJECT_H
