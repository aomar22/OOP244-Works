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
#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "LibApp.h"
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
    /*Method Implementations

Create new methods or Modify MS2 methods for the following
The load method

First print "Loading Data" and then open the data file for reading and read all the publications 
in dynamic instances pointed by the PPA Array.

Do this by first reading a single character for the type of publication and then dynamically 
instantiating the corresponding object into the next available PPA element. Then extract the object from
the file stream and add one to the NOLP. Since the extraction operator calls the proper read function virtually,
the object will be properly read from the file.

Continue this until the ifstream reading fails.

At the end set the LLRN to the reference number of the last publication read.

    See the pubSel_Tester.cpp that uses a similar logic to load the publications for example...
*/
    void LibApp::load() {  
        cout << "Loading Data" << endl;
        std::ifstream fin;
        fin.open("LibRecs.txt", std::ios::in);
        if (fin) {
            for (int i = 0; i < SENECA_LIBRARY_CAPACITY; i++) {
                char line;
                fin >> line;
                if (line == 'P') {
                    PPA = new Publication;
                }
                else if (line == 'B') {
                    PPA = new Book;
                }
            }
        }
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
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
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
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

    LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
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
                        
}
