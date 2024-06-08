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
    //  ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister& C);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
   
}

#endif // !SENECA_BOX_H
