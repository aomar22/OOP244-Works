/*Final Project Milestone 4
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
	
		char* m_title; //hold a dynamic title for the publication, null by default..
		char m_shelfId[SENECA_SHELF_ID_LEN +1]; //Hold the location of the publication in the library
		int m_membership; //hold a 5-digit membership number of members of the library.
		int m_libRef = -1; //used internally to uniquely identify each publication in the system.
		Date m_date; //by default, is set to the current date
	public:
		friend class Date;
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

}
#endif //SENECA_PUBLICATION_H