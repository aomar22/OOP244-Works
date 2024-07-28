#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
		
			ios.read(is);
		
		return is;
	}
	
	Streamable::~Streamable()
	{
	}
}
