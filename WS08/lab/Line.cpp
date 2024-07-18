#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Line.h"

//concrete class
//Line inherits the LblShape class to create a horizontal line with a label
using namespace std;
namespace seneca {
	Line::Line() : LblShape(){
		m_length = 0;
		cout << "invokes default constructor of the base class" << endl;// to be removed later
		/*Sets the m_length member variable to zero, and invokes
		the default constructor of the base class.*/
	}
	Line::Line(const char* str, int length) : LblShape(str), m_length(length) {
	
		/*Receives a Cstring and a value for
		the length of the line. Passes the Cstring to the
		constructor of the base class and sets the m_length member variable
		to the value of the second argument.*/
	}

	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label()) {
			os << label();
			os << '\n';
			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
			os << '\n';
		}
	}
		
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
	

	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(10000, '\n');

		/*Reads comma-separated specs of the Line from istream.
	This function overrides the getSpecs function of the base class as follows.
	First, it will call the getSpecs function of the base class
	then it will read the value of the m_length attribute from the
	istream argument, and then it will ignore The rest of the characters up to
	and including the newline character '\n'.*/
	}
}


