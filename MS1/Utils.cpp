/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"

using namespace std;
namespace seneca {
    Utils ut;
   /* unsigned*/ int Utils::getInt(/*unsigned*/ int min, /*unsigned*/ int max) {
       /* unsigned */int val = 0;
        cout << ">>>>>Enter";;
        cin >> val;
        while (cin.fail() || val < min || val > max) {
            cout << "Invalid Selection, try again: \n> ";
            cin.clear();
            cin.ignore(10000, '\n'); //ignores the 10000 characters
            cin >> val;
        }
        cin.ignore(10000, '\n'); //clear the keyboard

        return val;
    }

}