#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"
namespace seneca {
	class Rectangle : public LblShape {
		//The Rectangle class inherits the LblShape class 
		// to create a frame with a label inside
	private:
		// hold the width and the height of
		// a rectangular frame (number of characters).
		size_t m_height;//char m_height;
		size_t m_width;//char m_width;
		Rectangle();
		Rectangle(char label, size_t height, size_t width);
		//virtual ~Rectangle() = 0; // This class has no destructor implemented.
		//methods:
		void getSpecs(std::istream& is);//override
		void draw(std::ostream& os)const; //override
	};
}

#endif //RECTANGLE_H