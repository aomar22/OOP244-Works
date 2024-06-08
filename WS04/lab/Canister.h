#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H
#include <iostream>
namespace seneca {
   class Canister {
      char* m_contentName; //points to a dynamically allocated Cstring
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable; // a flag to identify if the Canister is usable or unusable
      /*This function sets the attributes to their default values. It sets the content name pointer to null, height to 13.0,
      diameter to 10.0, content volume to 0.0 and usable flag to true.*/
      void setToDefault();

      void setName(const char* Cstr); //dynamic memory //usable && not null before setting name
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const; //strcmp
   public:
       //constructors
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter,
         const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister& C);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
   void strnCpy(char des[], const char src[], int len);
   int strCmp(const char left[], const char right[]);
}
//in constructors resue settodefault 
//destructor:
//~thing(){
//delete [] in destructor context we don't need to write pointer = nullptr 
// after delallocation because the pointer is not accessble anyway after destruction. 
// if it is deallocation, assgin to nullptr.
#endif // !SENECA_BOX_H
/*
void display(const{
cout << name << endl;
}
call it by t1.display()

ostream& display2(){
cout ....
return cout           //cascading call it (t1.display2()) and can be used in place of cout
}*/