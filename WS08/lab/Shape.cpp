#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Shape.h"
using namespace std;
namespace seneca {

	/*Overload the insertion and extraction operators
	(using draw and getSpecs functions) so any shape object can be written or read using ostream and istream*/
	std::ostream& Shape::operator<<(std::ostream& os)
	{
		draw(os);
		return os;
	}
	std::istream& Shape::operator>>(std::istream& is)
	{
		getSpecs(is);
		return is;
	}
}
