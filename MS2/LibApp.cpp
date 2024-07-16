#include <iostream>
#include "LibApp.h"
namespace seneca {
    bool confirm(const char* message) {
        Menu m = message; //Instantiate a Menu in this function and initialize it with the message argument.
        //Then add only a "yes" as a single menu item to the Menu.
        m.save("yes");
        //Finally, run the menu and return true if the run method of Menu returns 1 otherwise this function returns false.
        if (m.run()) {
            return true;
        }
        else {
            return false;
        }
    }
    void LibApp::load() {  // prints: "Loading Data"<NEWLINE>
        cout << "Loading Data" << endl;
    }

}
