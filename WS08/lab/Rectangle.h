#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"
//concrete class
namespace seneca {
	class Rectangle : public LblShape {
		//The Rectangle class inherits the LblShape class 
		// to create a frame with a label inside
	private:
		// hold the width and the height of
		// a rectangular frame (number of characters).
		int m_height = 0;//char m_height;
		int m_width = 0;//char m_width;
		
	public:
		Rectangle();
		Rectangle(const char* label, int height, int width);
		//virtual ~Rectangle() = 0; // This class has no destructor implemented.
		//bool isValid();
		//methods:
		void getSpecs(std::istream& is);//override
		void draw(std::ostream& os)const; //override
	};
}

#endif //RECTANGLE_H
/**/