/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 18th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#ifndef LINE_H
#define LINE_H
#include <iostream>
#include "LblShape.h"
namespace seneca {
	class Line : public LblShape { 
		int m_length = 0;
	public:
		Line() : LblShape(), m_length(0) {};
		Line(const char* str, int length) : LblShape(str), m_length(length) {};
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif //LINE_H