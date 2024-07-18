#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "LblShape.h"
using namespace std;
namespace seneca {
	char* LblShape::label() const
	{
		return this->m_label;
	}
	LblShape::~LblShape()
	{
		delete m_label;
	}

	void LblShape::getSpecs(std::istream& is)
	{
		char line[500];
		is.getline(line,500, ',');
		delete m_label;
		m_label = new char[strlen(line) + 1];
		strcpy(m_label, line);
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label)
	{
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
}
