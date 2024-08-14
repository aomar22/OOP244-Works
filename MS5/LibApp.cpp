/* Citation and Sources...
Final Project Milestone 53
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
#include "LibApp.h"
using namespace std;
namespace seneca {
    LibApp::LibApp() {
        m_changed = false;
        m_mainMenu = "Seneca Library Application";
        m_exitMenu = "Changes have been made to the data, what would you like to do?";
        m_pubType = "Choose the type of publication:";
        m_fileName[0] = '\0';
        for (int i = 0; i < SENECA_LIBRARY_CAPACITY; i++) {
            PPA[i] = nullptr;
        }
        NOLP = 0;
        LLRN = 0;
        
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
       std:: cout << "Loading Data" << endl;
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
        std::cout << "Saving Data" << endl;
        std::ofstream fout;
        fout.open(m_fileName);
        if (fout) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i] && PPA[i]->getRef() != 0) {
                    fout << *PPA[i] << endl;
                }
            }
        } fout.close();
    }
    char getType(unsigned int num) {
        char ch = 'X';
        switch (num) {
        case 1:
            ch = 'B';
            break;
        case 2:
            ch = 'P';
            break;
        default:
            ch = 'X';
            break;
        }
        return ch;
    }
    int LibApp::search(int searchMode) {
        PublicationSelector ps("Select one of the following found matches:", 15);
        char userEnteredTitle[257]{};
        int refNum{};
      
        unsigned int pubType = m_pubType.run();
        char type = getType(pubType);
        bool matchFound = true;
        cout << "Publication Title: ";
        cin.getline(userEnteredTitle, 257);
            
        for (int i = 0; i < NOLP; i++) {
            switch (searchMode) {
                 case SENECA_ALL_SEARCH:
                     if (PPA[i] && type == PPA[i]->type() && strstr(*PPA[i], (const char*)userEnteredTitle) && PPA[i]->getRef()) {
                          matchFound = true;
                          ps << PPA[i];                         
                     }
                     break;
                case SENECA_SEARCH_ON_LOAN:
                     if (PPA[i] && type == PPA[i]->type() && strstr(*PPA[i], (const char*)userEnteredTitle) && PPA[i]->onLoan() && PPA[i]->getRef()) {
                          matchFound = true;
                          ps << PPA[i];                           
                     }
                     break;
                case SENECA_SEARCH_AVAILABLE_ITEMS:
                     if (PPA[i] && type == PPA[i]->type() && strstr(*PPA[i], (const char*)userEnteredTitle) && !PPA[i]->onLoan() && PPA[i]->getRef()) {
                          matchFound = true;
                          ps << PPA[i];                          
                     }
                     break;                  
            }
        }
        if (ps && matchFound == true) {
            ps.sort();
            refNum = ps.run();
            ps.reset();
            if (refNum == 0) {
                std::cout << "Aborted!" << std::endl;
                return -2;
            }
        }
        else {
            std::cout << "No matches found!" << std::endl;
        }
        return refNum;       
    }
    void LibApp::returnPub()
    {       
        std::cout << "Return publication to the library" << endl;
        int libRef = search(2);
        Publication* retPub = getPub(libRef);
        if (retPub)
        {
            cout << *retPub << endl;
        }
        if(confirm("Return Publication?")) {
           
            int loanDays = Date() - getPub(libRef)->checkoutDate();
            if (loanDays > SENECA_MAX_LOAN_DAYS) {
                int noOfLateDays = (loanDays - SENECA_MAX_LOAN_DAYS);
                double lateCharge = noOfLateDays * 0.50;
                std::cout << "Please pay $";
                std::cout.setf(std::ios::fixed);
                std::cout.precision(2);
                std::cout << lateCharge << " ";
                std::cout << "penalty for being ";
                std::cout << noOfLateDays << " ";
                std::cout << "days late!" << std::endl;
            }
        }
        retPub->set(0);
        m_changed = true;
        std::cout << "Publication returned" << std::endl;
    }
    void LibApp::newPublication() {
        if (NOLP >= SENECA_LIBRARY_CAPACITY) {
            std::cout << "Library is at its maximum capacity!" << endl;
           // m_exitMenu.run();
           // return;
        }
        else {
            std::cout << "Adding new publication to the library" << endl;
            Publication* pub = nullptr;

            int userChoice = m_pubType.run(); 
            switch (userChoice) {

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
            else {
                if (confirm("Add this publication to the library?")) {
                    if (pub) {

                        m_changed = true;
                        LLRN++;
                        pub->setRef(LLRN);
                        PPA[NOLP++] = pub;
                        NOLP++;
                        std::cout << "Publication added" << endl;
                        return;
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
        int retVal;
        int index = -1;

        cout << "Removing publication from the library" << endl;
        retVal = search(1);
        if (retVal > 0) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i] && PPA[i]->getRef() == retVal) {
                    index = i;
                }
            }
            if (index > -1) {
                cout << *PPA[index] << endl;
                if (confirm("Remove this publication from the library?")) {
                    PPA[index]->setRef(0);
                    m_changed = true;
                    delete PPA[index];  
                    PPA[index] = nullptr;  

                    cout << "Publication removed" << endl;
                }
            }
        }
    }  
    void LibApp::checkOutPub()
    {
        int membership{};
        int index{};
        cout << "Checkout publication from the library" << endl;
        int retVal = search(3);
        if (retVal > 0) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i] && PPA[i]->getRef() == retVal) {
                    index = i;
                }
            }
            if (index > -1) {
               cout << *PPA[index] << endl;
               if (confirm("Check out publication?")) {
                   cout << "Enter Membership number: ";
                   do {
                       cin >> membership;               
                       if (membership < 10000 || membership > 99999) {
                          cout << "Invalid membership number, try again:  ";
                       }
                   } while (membership < 10000 || membership > 99999);
                    PPA[index]->set(membership);
                    m_changed = true;
                    cout << "Publication checked out" << endl;
               }
            }
        }
    } 
    Publication* LibApp::getPub(int libRef)
    { 
        for (int i = 0; i < NOLP; i++) {
            if (PPA[i] && PPA[i]->getRef() == libRef) {//PPA[i]
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
                        done = true;
                    }
                    else if (userSelection == 0) {
                        confirm("This will discard all the changes are you sure?");
                        if (userSelection == 0) {
                            done = false; 
                        }
                    }
                }
                else {
                    done = true;
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
