#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"

namespace seneca {
   class LibApp {
       /*A flag to keep track of changes made to the application data. This flag is initially set to false.
       If any change is made to the data of the application, this flag is set to true.

Doing so, when exiting the program, we can warn the user and ask if they like the changes to be saved or discarded.*/
       bool m_changed;
       /*This menu will be used as the main menu of the application and should be initialized with
       the following title:

"Seneca Libray Application"

and then populated with the following menu items:

"Add New Publication"
"Remove Publication"
"Checkout publication from library"
"Return publication to library"
*/
       Menu m_mainMenu = "Seneca Library Application";
       /*This menu will be used when exiting the program if any changes are made to the data.
       This menu should be initialized with the following title:

"Changes have been made to the data, what would you like to do?"

and then populated with the following menu items:

"Save changes and exit"
"Cancel and go back to the main menu"
*/
       Menu m_exitMenu = "Changes have been made to the data, what would you like to do?";
      
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
      // Methods with confirmation
   public:
           void newPublication();
           void removePublication();
           void checkOutPub();
         //  Constructor

          /*     The constructor should initialize and set the attributes and load the publication records from the database

               Initializes the attributes(see the attribute section)
               populates the Menu attributes
               calls the `load()`` method*/
           //copy constructor:
           //virtual LibApp(const LibApp& L);
       //    virtual LibApp& operator=(const LibApp& L);
       //    virtual ~LibApp();
           LibApp();
           void run();
           unsigned int getMM(int n, int m);

   };
}
#endif // !SENECA_LIBAPP_H



