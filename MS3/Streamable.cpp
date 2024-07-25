#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace seneca {

	
	Streamable::~Streamable()
	{
	}
	std::ostream& operator>>(std::ostream& os, Streamable& str)
	{
		if (str) {
			return str.write(os);
		}
	}
	std::istream& operator<<(std::istream& is, const Streamable& str)
	{
		return str.read(is);
	}
}
/*Overload the insertion operator so a constant object of type Streamable can 
be written on an ostream object only if the Streamable object is in a valid state. Otherwise, 
the function will quietly ignore the insertion action.
Extraction operator overload

Overload the extraction operator so an object of type Streamable can be read from an istream object.*/