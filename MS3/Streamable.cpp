#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
#include "Streamable.h"

using namespace std;
namespace seneca {	
	ostream& operator<<(ostream& os, const Streamable& ios)
	{
		if (ios) {
			ios.write(os);
		}
	   return os;
	}
	istream& operator>>(istream& is, Streamable& ios)
	{
		if (ios) {
			ios.read(is);
		}
		return is;
	}
	/*Streamable::~Streamable()
	{
	}*/
	Streamable::~Streamable()
	{
	}
}
/*Overload the insertion operator so a constant object of type Streamable can 
be written on an ostream object only if the Streamable object is in a valid state. Otherwise, 
the function will quietly ignore the insertion action.
Extraction operator overload

Overload the extraction operator so an object of type Streamable can be read from an istream object.*/