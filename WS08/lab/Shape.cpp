#include <iostream>
#include "Shape.h"
using namespace std;
namespace seneca {

	/*Overload the insertion and extraction operators
	(using draw and getSpecs functions) so any shape object can be written or read using ostream and istream*/
	std::ostream& Shape::operator<<(std::ostream& os)
	{
		// TODO: insert return statement here
		return os;
	}
	std::istream& Shape::operator>>(std::istream& is)
	{
		// TODO: insert return statement here
		return is;
	}
}
