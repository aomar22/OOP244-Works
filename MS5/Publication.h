/*Final Project Milestone 5
Module: Publication
Filename : Publication.h
Version 1.0
Author	Amany Omar
Email : aomar22@myseneca.ca
ID : 126 127 166

---------------------------------------------------------- -
I have completed the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
namespace seneca {

	class Publication : public Streamable {
	
		char* m_title; 
		char m_shelfId[SENECA_SHELF_ID_LEN +1]; 
		int m_membership;
		int m_libRef = -1;
		Date m_date; 
	public:
		Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		//The Rule of three
		Publication(const Publication& p);
		Publication& operator=(const Publication& p);
		~Publication();
	};
	std::ostream& operator<<(std::ostream& os, const Publication& P);
	std::istream& operator>>(std::istream& istr, Publication& P);
}
#endif //SENECA_PUBLICATION_H