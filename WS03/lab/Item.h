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
      /*sets the itemName member Cstring variable 
      to a the Cstring in the name argument up to 20 characters.*/
   public:
       /*setEmpty: Sets the Item to a recognizable safe Empty State.
       Do this by setting the price to an impossible 
       value like 0.0 and setting the m_itemName to 
       a blank string (first character set to null).*/
      void setEmpty();
      /*set: Sets the m_itemName attribute to 
      the Cstring pointed by the name argument using the setName
      method and sets the m_price and m_taxed attributes to 
      the corresponding arguments.

If price is less than 0 or name is null, then the Item is set 
to a recognizable invalid empty state (safe empty state).*/
      void set(const char* name, double price, bool taxed);
      /*display: Prints an item in the following format.
If the Item is valid:{
"| "
m_itemName; left-justified in 20 spaces, padded with '.' (dots)
" | "
m_price; right-justified in 7 spaces with two digits after the decimal point
" | "
if m_taxed is true prints "Yes" otherwise prints "No "
" |"
Newline
}
if Item is invalid{
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
Newline
}
*/

      void display()const;
      /*isValid: Returns true if the Item is not set 
      to the empty state (As done in setEmpty function) .
      This function can not modify its owner.*/
      bool isValid()const;
      /*price: Returns the m_price attribute*/
      double price()const;
      /*Returns the product of m_price and 0.13
      (define a constant double value for this tax rate).
      Or it returns 0.0 if the m_taxed is false.*/
      double tax()const;
   };
}

#endif // !SENECA_SUBJECT_H
