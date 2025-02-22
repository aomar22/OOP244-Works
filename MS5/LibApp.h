/* Citation and Sources...
Final Project Milestone 5
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
#include <iostream>
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Lib.h"
namespace seneca {
   class LibApp {
       bool m_changed{};
       Menu m_mainMenu;
       Menu m_exitMenu;
       Menu m_pubType;
       char m_fileName[257]{};
       Publication* PPA[SENECA_LIBRARY_CAPACITY]{};
       int NOLP{};
       int LLRN{};
       bool confirm(const char* message);
       void load();  
       void save();  
       int search(int searchMode);
       void returnPub();  
       void newPublication();
       void removePublication();
       void checkOutPub();
       Publication* getPub(int libRef);
   public:
       LibApp();
       LibApp(const char* fileName);
       void run();
       ~LibApp();
       
   };
}

#endif // !SENECA_LIBAPP_H



