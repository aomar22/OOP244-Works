#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Rectangle.h"
#include "Line.h"
//Concrete class
//The Rectangle class inherits the LblShape class to create a frame with a label inside.
using namespace std;
namespace seneca {
	Rectangle::Rectangle() : LblShape(), m_height(0), m_width(0){
		/*m_height = 0;
		m_width = 0;*/
		
		/*Sets the width and height member variables to zero. It will also invoke
		the default constructor of the base class.*/
	}
	Rectangle::Rectangle(const char* label, int height, int width) : LblShape(label), m_height(height), m_width(width) {
		
		/*m_height = height;
		m_width = width;*/
		if (m_height < 3 || m_width < (LblShape::label() + 2)) {
			m_height = 0;
			m_width = 0;
		}
		/*Receives a Cstring for the label, and two values
		for the width and height of the Rectangle from the
		argument list. Passes the Cstring to the constructor of the base class 
		and sets the m_width and m_height member variables to the corresponding 
		values received from the argument list. 
		However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will set the Rectangle to an empty state.*/
	}
	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		char comma = ',';
		is >> m_width >> comma >> m_height;
		is.ignore(10000, '\n');
		
		/*Reads comma-separated specs of the Rectangle from istream.
	This function overrides the getSpecs function of the base class as follows.
	First, it will call the getSpecs function of the base class, then it will read two
	comma-separated values from istream for m_width and m_length and then ignores the rest of the characters up to
	and including the newline character ('\n').*/
	}
	/*bool Rectangle::isValid(Rectangle& r) {
		if (m_width != 0 && m_height != 0) {
			return true;
		}
		return false;
	}*/
	void Rectangle::draw(std::ostream& os) const
	{
		if (m_width != 0 && m_height != 0) {
			//1st line
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '+' << endl;

			//2nd line
			os << '|';
			os.width(m_width - 2);
			os.setf(ios::left);
			os << label();
			os << '|' << endl;
			//In next (m_height - 3) lines:
			os.width(m_height - 3);// not sure
			os << '|';
			os.width(m_width - 2);
			os << '|' << endl;
			//Last line: exactly like first line.
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '+' << endl;
		}
		/*This function overrides the draw function of the base class.
	If the Rectangle is not in an empty state, this function will draw a rectangle
	with a label inside as follows, otherwise, it will do nothing:

	First line:
	prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.

	Second line:
	prints '|', then in (m_width-2) spaces it prints the label() left justified and then prints '|' and goes to new line.

	In next (m_height - 3) lines:
	prints '|', (m_width-2) spaces then prints '|' and goes to new line.

	Last line: exactly like first line.

	For example, if the Cstring returned by the label query is "Container", 
	the width is 30 and the height is 5, this function should insert the following into ostream:

	+----------------------------+
	|Container                   |
	|                            |
	|                            |
	+----------------------------+
	*/
	}
}
