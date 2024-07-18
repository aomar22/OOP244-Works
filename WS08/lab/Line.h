#ifndef LINE_H
#define LINE_H
#include "LblShape.h"
//concrete class
namespace seneca {
	class Line : public LblShape { //concrete class
		//Line inherits the LblShape class to
		// create a horizontal line with a label.
		char m_length;//m_length to hold the length of the Line in characters
		Line();
		Line(char str, char length);
		//virtual ~Line() = 0; This class has no destructor implemented
		void getSpecs(std::istream& is);//override
		void draw(std::ostream& os) const;
	};
}

#endif //LINE_H