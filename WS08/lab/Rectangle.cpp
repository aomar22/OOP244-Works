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
		
	
	}
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_height(height), m_width(width) {

		if (m_height < 3 || m_width < (strlen(label) + 2)) {
			m_height = 0;
			m_width = 0;
		}
	}
	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		char comma = ',';
		is >> m_width >> comma >> m_height;
		is.ignore(10000, '\n');
	}
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
			os.width(m_width - 3);
			os.setf(ios::left);
			os.fill(' ');
			os << label();
			os << '|' << endl;
			//In next (m_height - 3) lines:
			for (int i = 0; i < (m_height - 3); i++) {
				os << '|';
				os.fill(' ');
				os.width(m_width - 2);
				os.unsetf(ios::left);
				os << '|' << endl;
			}
				////Last line: exactly like first line.
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '+';	
		}
	}
}
