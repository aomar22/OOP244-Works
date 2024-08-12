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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "LibApp.h"
#include "Book.h"
#include "Publication.h"
//#include "PublicationSelector.h"
#include "Lib.h"
#include "Streamable.h"

using namespace std;
namespace seneca {

    LibApp::LibApp(const char* fileName)
    {
        m_changed = false;
        m_mainMenu = "Seneca Library Application";
        m_exitMenu = "Changes have been made to the data, what would you like to do?";
        m_pubType = "Choose the type of publication: ";
        m_fileName[0] = '\0';
        for (int i = 0; i < SENECA_LIBRARY_CAPACITY; i++) {
            PPA[i] = nullptr;
        }
        NOLP = 0;
        LLRN = 0;
        if (fileName) {

            strcpy(m_fileName, fileName);
        }
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";

        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";

        m_pubType << "Book";
        m_pubType << "Publication";

        load();
    }
    bool LibApp::confirm(const char* message) {
        //Menu m = message;
        Menu m(message);
        m << "Yes";
        if (m.run() == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    void LibApp::load() {
        cout << "Loading Data" << endl;
        std::ifstream fin;
        fin.open(this->m_fileName, std::ios::in);
        for ( int i = 0; i < SENECA_LIBRARY_CAPACITY && fin;i++) {
           
            char line{};
            fin >> line;
            fin.ignore(); 
            if (line == 'P') {
                PPA[i] = new Publication;
            }
            else if (line == 'B') {
                 PPA[i] = new Book;
            }
            if (PPA[i]) {
               fin >> *PPA[i];
               NOLP++;
               LLRN = PPA[i]->getRef();
            }
        }
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        std::ofstream fout;
        fout.open(m_fileName, std::ios::out);
        if (fout) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i] != nullptr && PPA[i]->getRef() != 0) {
                    fout << *PPA[i] << endl;
                }
            }
        }
    }

    int LibApp::search(int searchMode)
    {
        cout << "Searching for publication" << endl;
        //get publication type from the user
        int userTypeSelection = m_pubType.run();
        
        //Get the title to search for
        cout << "Publication Title: ";
        char userEnteredTitle[265];
        cin.getline(userEnteredTitle, 256);

        //create a publicationSelector object with prompt and page size
        PublicationSelector ps("Select one of the following found matches:", 15);
        
        switch (searchMode) {

        case SENECA_ALL_SEARCH:
            for (int i = 0; i < NOLP; i++) { //searchAll
                if (ps && PPA[i]->operator==(userEnteredTitle) && PPA[i]->type()==userTypeSelection) {
                    ps << PPA[i];
                }
            }
            break;
        case SENECA_SEARCH_ON_LOAN:
            for (int i = 0; i < NOLP; i++) { //onLoan
                if (ps && PPA[i]->operator==(userEnteredTitle) && PPA[i]->type() == userTypeSelection && PPA[i]->onLoan()) {
                    ps << PPA[i];
                }
            }
            break;
        case SENECA_SEARCH_AVAILABLE_ITEMS:
            for (int i = 0; i < NOLP; i++) { //available items
                if (ps && PPA[i]->operator==(userEnteredTitle) && PPA[i]->type() == userTypeSelection && !PPA[i]->onLoan()) {
                    ps << PPA[i];
                }
            }
            break;
        case 0:
            cout << "Abort!";
        }
        if (ps) {
            ps.sort();
           /* int libRef = ps.run();*/
            
        }
        else {
            cout << "No matches found!";
        }  
        int libRef = ps.run();
        return libRef;
    }
    void LibApp::returnPub()
    {
        
        cout << "Return publication to the library" << endl;
        int libRef = search(SENECA_SEARCH_ON_LOAN);
        Publication* retPub = getPub(libRef);
        if (confirm("Return Publication?")) {
            int loanDays = Date() - getPub(libRef)->checkoutDate();
            if (loanDays > SENECA_MAX_LOAN_DAYS) {
                int noOfLateDays = (loanDays - SENECA_MAX_LOAN_DAYS);
                double lateCharge = noOfLateDays * 0.50;
                cout << "Please pay $";
                cout.precision(2);
                cout << lateCharge;
                cout << "penalty for being ";
                cout << noOfLateDays;
                cout << "days late!" << endl;
            }
        }
        retPub->set(0);
        m_changed = true;
        cout << "Publication returned" << endl;  
    }
     void LibApp::newPublication(){      
        if (NOLP >= SENECA_LIBRARY_CAPACITY) {
             std::cout << "Library is at its maximum capacity!" << endl;
                m_exitMenu.run();
                return;
        }
        else {
            std::cout << "Adding new publication to the library" << endl;
            Publication* pub = nullptr;
          
            int userChoice = m_pubType.run();
            switch(userChoice){
            
            case 1: 
                pub = new Book();
                cin >> *pub;
                break;
            case 2: 
                pub = new Publication();
                cin >> *pub;
                break;
            case 0:
                std::cout << "Aborted!" << endl;
                m_exitMenu.run();
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                std::cout << "Aborted!" << endl;
                m_exitMenu.run();
                return;
            }
            else{
                if (confirm("Add this publication to the library?")) {
                    if (pub != nullptr) {

                        m_changed = true;
                        LLRN++;
                        pub->setRef(LLRN);
                        PPA[NOLP++] = pub;
                        NOLP++;
                        std::cout << "Publication added" << endl;
                    }
                    else {
                        std::cout << "Failed to add publication!" << std::endl;
                    }
                }
            }
        }

     }
    void LibApp::removePublication()
    {
        Publication* pub = nullptr;
        cout << "Removing publication from library" << endl;
        search(SENECA_ALL_SEARCH);
        if (confirm("Remove this publication from the library?")) {
            pub->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }
    
    void LibApp::checkOutPub()
    {
        search(SENECA_SEARCH_AVAILABLE_ITEMS);
        if (confirm("Check out publication?")) {
            cin >> LLRN;
            while (!cin >> LLRN) {
                cout << "Invalid membership number, try again: ";
                cin >> LLRN;
            }
           
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }
   
    Publication* LibApp::getPub(int libRef)
    { 
        for (int i = 0; i < NOLP; i++) {
            if (PPA[i]->getRef() == libRef) {
               return PPA[i];
            }
        }
        return nullptr;
    }
   
    void LibApp::run()
    {
        bool done = true;   
        while (done) {
            unsigned int userSelection = m_mainMenu.run();
           
            switch (userSelection) {
            
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    userSelection = m_exitMenu.run();
                    if (userSelection == 1) {
                        save();
                        done = false;
                    }
                    else if (userSelection == 0) {
                        confirm("This will discard all the changes are you sure?");
                        if (userSelection == 0) {
                            done = false; 
                        }
                    }
                }
                else {
                    done = false;
                }
                break;
            }
            cout << endl;
        }
            cout << "-------------------------------------------" << endl;
            cout << "Thanks for using Seneca Library Application" << endl;
    }
    LibApp::~LibApp()
    {
        for (int i = 0; i < NOLP; i++) {
            delete PPA[i];
        }
    }
                        
}
