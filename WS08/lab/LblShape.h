/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 18th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace seneca {
	class LblShape : public Shape { 
		char* m_label = nullptr; 
	protected:
		char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(LblShape& lShape) = delete;
		LblShape& operator=(LblShape& lShape) = delete;
		void getSpecs(std::istream& is); 
		virtual void draw(std::ostream& os) const = 0;
	};
}

#endif  //LBLSHAPE_H