/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
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
#ifndef SENECA_UTILS_H__
#define SENECA_UTILS_H__

using namespace std;
namespace seneca {
	class Utils {
	public:
		unsigned int getInt(size_t min, size_t max);
	};
	extern Utils ut;
}
#endif // SENECA_UTILS_H__
