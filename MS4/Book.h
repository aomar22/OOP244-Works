/*Final Project Milestone 4
Module: Book
Filename : Book.h
Version 1.0
Author	Amany Omar
Email : aomar22@myseneca.ca
ID : 126 127 166

---------------------------------------------------------- -
I have completed the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "Publication.h"
namespace seneca {
	class Book : public Publication {
		char* m_author{ nullptr };
	public:
		
		Book() : Publication(), m_author(nullptr) {};
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		//overrides:
		char type()const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;
	};
}

#endif