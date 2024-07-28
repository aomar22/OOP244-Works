/*Final Project Milestone 3
Module: Streamable
Filename : Streamable.cpp
Version 1.0
Author	Amany Omar
Email : aomar22@myseneca.ca
ID : 126 127 166

---------------------------------------------------------- -
I have completed the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace seneca {	
	ostream& operator<<(ostream& os, const Streamable& ios)
	{
		if (ios) {
			ios.write(os);
		}
	   return os;
	}
	istream& operator>>(istream& is, Streamable& ios)
	{
			ios.read(is);
		return is;
	}
	
	Streamable::~Streamable()
	{
	}
}
