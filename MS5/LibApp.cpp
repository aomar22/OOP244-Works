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
#include <string>
#include "Menu.h"
#include "LibApp.h"
#include "Book.h"
#include "Publication.h"
#include "Lib.h"
#include "Streamable.h"
//#include "PublicationSelector.h"
using namespace std;
namespace seneca {
    bool LibApp::confirm(const char* message) {
        Menu m = message; 
        m << "Yes";
        if (m.run()==1) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void LibApp::load() {  
        cout << "Loading Data" << endl;
        std::ifstream fin;
        fin.open("LibRecsSmall.txt", std::ios::in);
        if (fin) {
            for (int i = 0; fin ; i++) {
            
                char line{};
                fin >> line;
                fin.ignore(); //ignore tab character
                if (line == 'P') {
                    PPA[i] = new Publication[SENECA_LIBRARY_CAPACITY];
                }
                else if (line == 'B') {
                    PPA[i] = new Book[SENECA_AUTHOR_WIDTH];
                }
                if (PPA[i]) {
                    fin >> *PPA[i];
                    NOLP++;
                    LLRN = PPA[i]->getRef();
                }
            
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
                if (PPA[i]->getRef() != 0) {
                    fout << *PPA[i] << endl;
                }
            }
        }
    }

    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        Publication* pub = nullptr;
        pub = new Publication[SENECA_LIBRARY_CAPACITY]; //instantiate a dynamic "Publication"
        if (NOLP == SENECA_LIBRARY_CAPACITY) {
            std::cout << "Library is at its maximum capacity!" << endl;
            m_exitMenu.run();
        }
        else {
            std::cout << "Adding new publication to library" << endl;
            
            int userChoice = m_pubType.run();
            
            if (userChoice == 1) {
                std::cout << m_pubType;
                char type = '\0';
                cin >> type;
              
                if (type == 'P') {
                    
                    cin >> *pub; //Read the instantiated object from the cin object.
                }
                else if (type == 'B') {
                    pub = new Book(); //instantiate a dynamic "Book"
                    cin >> *pub; //Read the instantiated object from the cin object.
                }
            } 
            //If the cin fails, flush the keyboard, print "Aborted!" and exit.
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
               std::cout << "Aborted!";
                m_exitMenu.run();
            }
            if (confirm("Add this publication to library?")) {
                m_changed = true;

               /* std::cout << "Publication added" << endl;*/
            }
            else {
                std::cout << "Aborted!";
                m_exitMenu.run();
            }
            if (*pub) {
                LLRN++;
                pub->setRef(LLRN);
                pub = PPA[NOLP];
                NOLP++;
                m_changed = true;
                std::cout << "Publication added" << endl;
            }
            else {
                cout << "Failed to add publication!" << endl;
                delete[] pub;
            }
           
        }
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?")) {
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

   /* LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";
       
        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";
        load();
    }*/
   
    LibApp::LibApp(const char* fileName)
    {
        m_changed = false;
        m_mainMenu = "Seneca Library Application";
        m_exitMenu = "Changes have been made to the data, what would you like to do?";
        m_pubType = "Choose the type of publication : ";
        m_fileName[0] = '\0';
        PPA[0] = nullptr;
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
        load();
        

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
