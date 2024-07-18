/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 18th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Line.h"
using namespace std;
namespace seneca {
	
	void Line::draw(std::ostream& os) const 
	{
		if (m_length > 0 && label()){
			os << label();
			os << '\n';
			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
		}
	}
	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(10000, '\n');
	}
}


