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
     // void strncopy(char des[], const char src[], int len);
   };
}

#endif // !SENECA_SUBJECT_H
