#include <iostream>
#include <cstring>
#include "Rectangle.h"
//The Rectangle class inherits the LblShape class to create a frame with a label inside.
using namespace std;
namespace seneca {
	Rectangle::Rectangle() {
		/*Sets the width and height member variables to zero. It will also invoke
		the default constructor of the base class.*/
	}
	Rectangle::Rectangle(char label, size_t height, size_t width) {
		/*Receives a Cstring for the label, and two values
		for the width and height of the Rectangle from the
		argument list. Passes the Cstring to the constructor of the base class and sets the m_width and m_height member variables to the corresponding values received from the argument list. However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will set the Rectangle to an empty state.*/
	}
	void Rectangle::getSpecs(std::istream& is)
	{
		/*Reads comma-separated specs of the Rectangle from istream.
	This function overrides the getSpecs function of the base class as follows.
	First, it will call the getSpecs function of the base class, then it will read two comma-separated values from istream for m_width and m_length and then ignores the rest of the characters up to
	and including the newline character ('\n').*/
	}
	void Rectangle::draw(std::ostream& os) const
	{
		/*This function overrides the draw function of the base class.
	If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:

	First line:
	prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.

	Second line:
	prints '|', then in (m_width-2) spaces it prints the label() left justified and then prints '|' and goes to new line.

	In next (m_height - 3) lines:
	prints '|', (m_width-2) spaces then prints '|' and goes to new line.

	Last line: exactly like first line.

	For example, if the Cstring returned by the label query is "Container", the width is 30 and the height is 5, this function should insert the following into ostream:

	+----------------------------+
	|Container                   |
	|                            |
	|                            |
	+----------------------------+
	*/
	}
}
