#include <iostream>
#include <cstring>
#include "Line.h"
//concrete class
//Line inherits the LblShape class to create a horizontal line with a label
using namespace std;
namespace seneca {
	Line::Line() {
		/*Sets the m_length member variable to zero, and invokes
		the default constructor of the base class.*/
	}
	Line::Line(char str, char length) {
		/*Receives a Cstring and a value for
		the length of the line. Passes the Cstring to the
		constructor of the base class and sets the m_length member variable
		to the value of the second argument.*/
	}

	void Line::draw(std::ostream& os) const
	{
		/*This function overrides the draw function of the base class.
	If the m_length member variable is greater than zero and the label() is not null,
	this function will first print the label() and then go to the new line.
	Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
	Otherwise, it will take no action.

	For example, if the Cstring returned by the label query is "Separator"
	and the length is 40, the draw function should insert the following into ostream:

	Separator
	========================================
	*/
	}

	void Line::getSpecs(std::istream& is)
	{
		/*Reads comma-separated specs of the Line from istream.
	This function overrides the getSpecs function of the base class as follows.
	First, it will call the getSpecs function of the base class
	then it will read the value of the m_length attribute from the
	istream argument, and then it will ignore The rest of the characters up to
	and including the newline character '\n'.*/
	}
}


