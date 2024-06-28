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
	void flushKey(void) {
		char ch = 'x';
		while (ch != '\n') {
			std::cin.get();
		}
	}

}