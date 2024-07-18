#ifndef LINE_H
#define LINE_H
#include <iostream>
#include "LblShape.h"
//concrete class
namespace seneca {
	class Line : public LblShape { //concrete class
		//Line inherits the LblShape class to
		// create a horizontal line with a label.
		int m_length = 0;//m_length to hold the length of the Line in characters
	public:
		Line() : LblShape(), m_length(0) {};
		Line(const char* str, int length) : LblShape(str), m_length(length) {};
		//virtual ~Line() = 0; This class has no destructor implemented
		void getSpecs(std::istream& is);//override
		void draw(std::ostream& os) const;//overrides
	};
}

#endif //LINE_

//lefthand side if there is virtual
// if no virtual choose right hand sideH