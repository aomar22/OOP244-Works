#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "LblShape.h"
/*Inherit an abstract class from 
the interface Shape called LblShape. This class adds a label to a Shape.

This class will implement the pure virtual 
function getSpecs but will not implement the draw function; therefore it remains abstract.*/
using namespace std;
namespace seneca {
	char LblShape::label() const
	{
		/*Add a query called label that returns the unmodifiable value of m_label member variable.*/
		return *m_label;
	}
	LblShape::~LblShape()
	{
		delete m_label;
		/*Deletes the memory pointed by m_label member variable.
	deleted actions*/
	}

	void LblShape::getSpecs(std::istream& is)
	{
		char line[500];
		is.getline(line,500);
		is.ignore(',');
		delete m_label;
		m_label = new char[strlen(line) + 1];
		strcpy(m_label, line);
		/*Reads a comma-delimited Cstring form istream:
	Override the Shape::getSpecs pure virtual function to
	receive a Cstring (a label) from istream up to the ',' character
	(and then extract and ignore the comma). Afterward, follow the same logic
	as was done in the one argument constructor; allocate memory large enough to
	hold the Cstring and copy the Cstring into the newly allocated memory.*/
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
		//Sets the label pointer to null. (You don't need to do this if the m_label is already initialized to null)
		//One argument constructor
	}

	LblShape::LblShape(const char* label)
	{
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);

		/*Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable.
		Then copies the Cstring
		argument to the newly allocated memory.*/
	}
	//LblShape& LblShape::operator&()
	//{
	//	// TODO: insert return statement here
	//}
	//void LblShape::set()
	//{
	//}
}
