#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include <iostream>
#include "Shape.h"

namespace seneca {
	class LblShape : public Shape { //labeled shape class
		char* m_label = nullptr; //hold dynamically allocated label for  the Shape

	protected:
		char label()const;//Add a query called label that returns the unmodifiable value of m_label member variable
	public:
		
		//methods:
		LblShape();
		LblShape(char* str);
		~LblShape();
		//deleted
		LblShape(LblShape& lShape) = delete;
		LblShape& operator=(LblShape& lShape) = delete;
		virtual void getSpecs(std::istream& is); //override shape getspecs
		
		//LblShape& operator&();
		//void set();

	};
}

#endif  //LBLSHAPE_H