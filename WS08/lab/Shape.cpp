#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Shape.h"
using namespace std;
namespace seneca {

	/*Overload the insertion and extraction operators
	(using draw and getSpecs functions) so any shape object can be written or read using ostream and istream*/
	std::ostream& operator<<(std::ostream& os, Shape& s)
	{
		s.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& s)
	{
		s.getSpecs(is);
		return is;
	}
}
