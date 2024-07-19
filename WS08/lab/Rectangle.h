/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 18th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"
namespace seneca {
	class Rectangle : public LblShape {
	private:
		int m_height = 0;
		int m_width = 0;
	public:
		Rectangle() : LblShape(), m_height(0), m_width(0) {};
		Rectangle(const char* label, int height, int width);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os)const;
		operator int()const;
	};
}
	
#endif //RECTANGLE_H