#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include <iostream>
#include "Shape.h"
//ABSTRACT
namespace seneca {
	class LblShape : public Shape { //labeled shape class
		char* m_label = nullptr; //hold dynamically allocated label for  the Shape

	protected:
		char* label()const;//Add a query called label that returns the unmodifiable value of m_label member variable
	public:
		
		//methods:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		//deleted
		//The copy constructor and assignment operator are deleted to prevent copying
		//or assignment of instances of this class.* /
		LblShape(LblShape& lShape) = delete;
		LblShape& operator=(LblShape& lShape) = delete;
		void getSpecs(std::istream& is); //we don't override shape getspecs
		virtual void draw(std::ostream& os) const = 0;
		
		//LblShape& operator&();
		//void set();

	};
}

#endif  //LBLSHAPE_H