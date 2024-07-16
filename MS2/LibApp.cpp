#include <iostream>
#include "LibApp.h"
using namespace std;
namespace seneca {
    bool LibApp::confirm(const char* message) {
        Menu m = message; //Instantiate a Menu in this function and initialize it with the message argument.
        //Then add only a "yes" as a single menu item to the Menu.
        m << "yes";
        //Finally, run the menu and return true if the run method of Menu returns 1 otherwise this function returns false.
        if (m.run()) {
            return true;
        }
        else {
            return false;
        }
    }
   
    /*// prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;*/
    void LibApp::load() {  // prints: "Loading Data"<NEWLINE>
        cout << "Loading Data" << endl;
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
        confirm("Add this publication to library?");
        cout << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        confirm("Remove this publication from the library?");
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        confirm("Check out publication?");
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }
    LibApp::LibApp()
    {
      //  m_mainMenu << "Seneca Library Application";
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";
       

      //  m_exitMenu << "Changes have been made to the data, what would you like to do?";
        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";
        m_changed = false;
        load();
    }

    void LibApp::run()
    {
        // Menu m;
        int done = 0;
        int userSelection = 1;
        
            m_mainMenu.run();

      ///  while(done != 0){
            
            switch (userSelection) {
            case 1:
                newPublication();
               // save();
                break;
            case 2:
                removePublication();
                m_mainMenu.run();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                   m_exitMenu.run();
                   m_mainMenu.run();
                }
               
            default:
                done = 0;
            }

            cout << "-------------------------------------------" << endl;
            cout << "Thanks for using Seneca Library Application" << endl;
       // }

        
    }
    
    /*When the user selects exit, the value of m_changed is examined.
    If the value is false, then since the data of the application is not modified, the program terminates.*/
    /*loop until done
    display menu
    if first option  new publication otherwise
    if second option remove publication otherwise
    if third option checkout otherwise
    if fourth option return publication otherwise 
        if changed
           Warning menu and choices
           if save selected save and its done otherwise
           if discard selected 
              final confirmation for exit 
              if exit selected 
                 its done (no saving)   
              end if
           end if
        otherwise (no change)
           it is done          
        end if
    end if
end loop        
goodbye message*/
}
