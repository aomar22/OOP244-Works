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

#include "Utils.h"
#include <iostream>
namespace seneca {
    int getIntMM(int min, int max, int value) {
        std::cout << "> ";
        std::cin >> value;
        while (value < min || value > max) {

            printf("Invalid Integer, try again: ");
        }
        return value;
    }
}
   /* int getInt() {
        int value;
        int done = 0;
        char newline = 'x';
        while (!done) {
            if (std::cin >> "%d%c" >> &value >> &newline)  {
                if (newline == '\n') {
                    done = 1;
                }
                else {
                    printf("Please enter only an integer: ");
                    flushKey();
                }
            }
            else { 
                flushKey();
                printf("Invalid Integer, try again: ");
            }
        }
        return value;
    }

*/