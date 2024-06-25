/*Name: Amany Omar
  Email: aomar22@myseneca.ca 
  ID# 126127166
  Completed on July 1st, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace seneca {
    //Returns the address held in the m_value attribute.
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   //Dynamically allocates memory in 
   // m_value and copies the Cstring pointed by lineContent into it.
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
       //Makes sure all the allocated memory is freed.
       //Make sure Line can not be copied or assigned 
       // to another Line.

      delete[] m_value;
   }
   Line::Line() { //default constructor
       //Initializes the m_value attribute to nullptr
       m_value = nullptr;
   }
   void TextFile::setEmpty() {
       //deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring 
       // and sets is to nullptr sets m_noOfLines attribute to zero.
       delete[] m_textLines;
       m_textLines = nullptr;

       delete[] m_filename;
       m_filename = nullptr;

       m_noOfLines = 0;
   }

}
