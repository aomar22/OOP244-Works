/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Amany Omar
Email: aomar22@myseneca.ca
ID: 126 127 166
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
/*Add the following attributes to the LibApp Module.




Publication Type Menu

Add a Menu to the LibApp for selection of publication type. The title of this menu is: "Choose the type of publication:"

The publication type menu should also provide two selections: "Book" and "Publication".

Setup the publication type menu in the constructor as you did for the main and exit menus.*/

namespace seneca {
   class LibApp {
       
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
      /* Publication Type Menu

           Add a Menu to the LibApp for selection of publication type.The title of this menu is : "Choose the type of publication:"

           The publication type menu should also provide two selections : "Book" and "Publication".

           Setup the publication type menu in the constructor as you did for the main and exit menus.*/
       Menu m_pubType{ "Choose the type of publication : "};
       char m_fileName[256 + 1];//
       Publication* PPA[SENECA_LIBRARY_CAPACITY]; //array of Publication pointers to the size of SENECA_LIBRARY_CAPACITY.
      // This array will be populated with all the records of the publication data file when the LibApp is instantiated.
       
       int NOLP; //number of Publications loaded into the PPA
       /*Last Library Reference Number 
This number will be used to assign new library reference numbers to new publications added 
to the library. When a new publication is added to the library, this number will be added by one
and then assigned to the new publication. Doing this; each publication in the library will have a unique
library reference number.

    We will call this attribute "LLRN" for short, from now on.*/
       int LLRN;//last library reference number read from the data file



       bool confirm(const char* message);
       void load();  
       void save();  
       void search();  
       void returnPub();  
       void newPublication();
       void removePublication();
       void checkOutPub();
       Publication* getPub(int libRef);
   public:
           LibApp();
           void run();
   };
}

#endif // !SENECA_LIBAPP_H



