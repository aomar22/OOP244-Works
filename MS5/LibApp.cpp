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
//#include <string>
//#include "Menu.h"
#include "LibApp.h"
//#include "Book.h"
//#include "Publication.h"
//#include "PublicationSelector.h"
//#include "Lib.h"
//#include "Streamable.h"

using namespace std;
namespace seneca {
    LibApp::LibApp() {
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
        fout.open(m_fileName, std::ios::out);
        if (fout) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i] != nullptr && PPA[i]->getRef() != 0) {
                    fout << *PPA[i] << endl;
                }
            }
        }
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
    //int LibApp::search(int searchMode)
    //{
    //    // ifstream infile("LibRecsSmall.txt");
    //    // Publication* p[1000]{};
    //    PublicationSelector ps("Select one of the following found matches:", 15);
    //    char* userEnteredTitle{};
    //    int refNumber{};
    //    int userTypeSelection{};
    //    bool ok{};

    //    userEnteredTitle = new char[256];
    //    userTypeSelection = m_pubType.run();

    //    //Get the title to search for


    //    //create a publicationSelector object with prompt and page size
    //    cout << "Publication Title: ";

    //    cin.getline(userEnteredTitle, 265);
    //    //  if(searchMode == 1){
    //         //serTypeSelection = m_pubType.run();
    //    switch (userTypeSelection) {

    //    case 1:
    //        //cin.ignore();

    //        for (int i = 0; i < NOLP; i++) { //searchAll
    //            if (PPA[i]->getRef() && *PPA[i] == (userEnteredTitle) && PPA[i]->type() == userTypeSelection) {
    //                ok = true;
    //                ps << *PPA[i];

    //            }
    //        }
    //        /*if (ok) {
    //            ps.sort();
    //            refNumber = ps.run();
    //            if (refNumber == 0) {
    //                cout << "Aborted!" << endl;
    //            }
    //        }
    //        else {
    //            cout << "No matches found!" << endl;*/
    //        break;
    //    case 2:
    //        //  cin.ignore();
    //          /*cout << "Publication Title: ";
    //          cin.getline(userEnteredTitle, 256);*/
    //        for (int i = 0; i < NOLP; i++) { //searchAll
    //            if (PPA[i]->getRef() && *PPA[i] == userEnteredTitle && PPA[i]->type() == userTypeSelection && PPA[i]->getRef()) {
    //                ok = true;
    //                ps << *PPA[i];

    //            }
    //        }
    //        /*if (ok) {
    //            ps.sort();
    //            refNumber = ps.run();
    //            if (refNumber == 0) {
    //                cout << "Aborted!" << endl;
    //            }
    //        }
    //        else {
    //            cout << "No matches found!" << endl;*/

    //        break;
    //    case 3:

    //        for (int i = 0; i < NOLP; i++) { //available items
    //            if (PPA[i]->getRef() && *PPA[i] == userEnteredTitle && PPA[i]->type() == userTypeSelection && !PPA[i]->onLoan()) {
    //                ps << PPA[i];
    //                ok = true;

    //            }
    //        }
    //        break;
    //    case 0:
    //        cin.ignore();
    //        cout << "Aborted!" << endl;
    //        //  ok = false;
    //    }
    //    if (ok) {
    //        ps.sort();
    //        refNumber = ps.run();
    //    }
    //    else {
    //        cout << "No matches found!" << endl;
    //    }
    //    delete[]  userEnteredTitle;
    //    return  refNumber;
    //}

 
    int LibApp::search(int searchMode) {
        PublicationSelector ps("Select one of the following found matches:", 15);
        char userEnteredTitle[257]{};
        int refNum{};
        //get the type of publication to search for from the user. (user the type selection Menu of the class)
       unsigned int pubType = m_pubType.run();
        //char userTypeSelected{};
        char type = getType(pubType);
        bool matchFound = true;
       /* if (userTypeSelected == 'X') {
            std::cout << "Aborted!" << endl;
            refNum = -1;
        }*/
      //  else {
            cout << "Publication Title: ";
            cin.getline(userEnteredTitle, 257);
            
            for (int i = 0; i < NOLP; i++) {
               // if (PPA[i]) {
                    switch (searchMode) {
                    case SENECA_ALL_SEARCH:
                        if (PPA[i] && type == PPA[i]->type()/*userTypeSelected*/ && strstr(*PPA[i], (const char*)userEnteredTitle) && PPA[i]->getRef())/* && (PPA[i]->onLoan() || !PPA[i]->onLoan())*/ {
                            /*if (type == 'P') {
                                PPA[i] = new Publication();
                            }
                            else if (type == 'B') {
                                PPA[i] = new Book();
                            }*/
                            matchFound = true;
                            ps << PPA[i];
                           
                        }
                        
                        /*if (PPA[i]) {
                            ps << PPA[i];
                        }*/
                        break;
                    case SENECA_SEARCH_ON_LOAN:
                        if (PPA[i] && type == PPA[i]->type()/*userTypeSelected*/ && strstr(*PPA[i], (const char*)userEnteredTitle) && PPA[i]->onLoan()) {
                            /*if (type == 'P') {
                                PPA[i] = new Publication();
                            }
                            else if (type == 'B') {
                                PPA[i] = new Book();
                            }*/
                            matchFound = true;
                            ps << PPA[i];
                           
                        }
                        /*if (PPA[i]) {
                            ps << PPA[i];
                        }*/
                        break;
                    case SENECA_SEARCH_AVAILABLE_ITEMS:
                        if (PPA[i] && type == PPA[i]->type()/*userTypeSelected*/ && strstr(*PPA[i], (const char*)userEnteredTitle) && !PPA[i]->onLoan()) {
                           /* if (type == 'P') {
                                PPA[i] = new Publication();
                            }
                            else if (type == 'B') {
                                PPA[i] = new Book();
                            }
                            if (PPA[i]) {
                                ps << PPA[i];
                            }*/
                            matchFound = true;
                            ps << PPA[i];
                            
                        }
                        break;                  
                    }
               // }
            }
        //}
        
        //if (ps) {
        if (matchFound == true) {
            ps.sort();
            refNum = ps.run();
            ps.reset();
            if (refNum == 0) {
                std::cout << "Aborted!" << std::endl;
                return -2;
            }
        }
        else {
            matchFound == false;
            std::cout << "No matches found!" << std::endl;
        }
        return refNum;       
    }



    void LibApp::returnPub()
    {
        
        std::cout << "Return publication to the library" << endl;
        int libRef = search(2);
        Publication* retPub = getPub(libRef);
        if (confirm("Return Publication?")) {
            int loanDays = Date() - getPub(libRef)->checkoutDate();
            if (loanDays > SENECA_MAX_LOAN_DAYS) {
                int noOfLateDays = (loanDays - SENECA_MAX_LOAN_DAYS);
                double lateCharge = noOfLateDays * 0.50;
                std::cout << "Please pay $";
                std::cout.precision(2);
                std::cout << lateCharge;
                std::cout << "penalty for being ";
                std::cout << noOfLateDays;
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
            m_exitMenu.run();
            return;
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
        int retVal;
        int index = -1;

        cout << "Removing publication from the library" << endl;
        retVal = search(1);
        if (retVal > 0) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i]->getRef() == retVal) {
                    index = i;
                }
            }
            if (index > -1) {
                cout << *PPA[index] << endl;
                if (confirm("Remove this publication from the library?")) {
                    PPA[index]->setRef(0);
                    m_changed = true;
                    delete PPA[index];  // Free memory
                    PPA[index] = nullptr;  // Avoid dangling pointer

                    cout << "Publication removed" << endl;
                }
            }
        }
    }
    
    void LibApp::checkOutPub()
    {
        int membership{};
        int membershipLength{};
        int index{};
        cout << "Checkout publication from the library" << endl;
        int retVal = search(3);
        if (retVal > 0 && /*PPA->m_pubType == 'P*/ confirm("Check out publication ? ")) {
            for (int i = 0; i < NOLP; i++) {
                if (PPA[i]->getRef() == retVal) {
                    index = i;
                }
                if (index > -1) {
                    cout << *PPA[index] << endl;
                }
                if (confirm("Check out publication?")) {
                    cout << "Enter Membership number: ";
                    do {
                        cin >> membership;
                
                        if (membershipLength != 5) cout << "Invalid membership number, try again:  ";
                    } while (membershipLength != 5);
                    PPA[index]->set(membershipLength);
                    m_changed = true;
                    cout << "Publication checked out" << endl;
                }
            }
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
