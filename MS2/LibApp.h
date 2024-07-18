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

namespace seneca {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       bool confirm(const char* message);
       void load();  
       void save();  
       void search();  
       void returnPub();  
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
           LibApp();
           void run();
   };
}
#endif // !SENECA_LIBAPP_H



