/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 18th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Shape.h"
using namespace std;
namespace seneca {
	std::ostream& operator<<(std::ostream& os, Shape& s)
	{
		s.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& s)
	{
		s.getSpecs(is);
		return is;
	}
}
