/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 18th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
namespace seneca {
	class Shape {
	public:
		virtual ~Shape() = default; 
	    virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0; 
	};
	std::ostream& operator<<(std::ostream& os, Shape& s);
	std::istream& operator>>(std::istream& is, Shape& s);
}

#endif //SHAPE_H