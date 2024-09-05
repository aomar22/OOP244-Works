/*Final Project Milestone 52
Module: Publication
Filename : Publication.cpp
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
#include <cstring>
#include <string>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"

using namespace std;
namespace seneca {

	Publication::Publication(): m_date(Date()) {
		m_title = nullptr;
		m_shelfId[0] = {'\0'}; 
		m_membership = 0; 
		m_libRef = -1;
	}
	void Publication::set(int member_id)
	{
		if (member_id >=10000 && member_id < 99999) {
			m_membership = member_id;
		}
		else{
			m_membership = 0;
		}
	}
	void Publication::setRef(int value)
	{
		if (value) {
			m_libRef = value;
		}
	}
	void Publication::resetDate()
	{
		m_date = Date();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan()const {
		return m_membership != 0;
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		if (m_title == nullptr || title == nullptr) {
			return false;
		}
		return (strstr(m_title, title) != nullptr);
	}
	Publication::operator const char* () const
	{
		return m_title;
	}
	int Publication::getRef() const
	{   
		return m_libRef;
	}

	bool Publication::conIO(ios& io)const
	{
		return (&io == &cin || &io == &cout);
	}
	
    ostream& Publication::write(std::ostream& os)const
	{
		
		if (conIO(os)) {
			os << "| ";
			os << m_shelfId;
			os << " | ";
			if (strlen(m_title) > SENECA_TITLE_WIDTH) {
				os.write(m_title, SENECA_TITLE_WIDTH);
			}
			else {
				
				os.width(SENECA_TITLE_WIDTH);
				os.fill('.');
				os.setf(ios::left);
				os << m_title;
				os.unsetf(ios::left);
			}
			os << " | ";
			if (onLoan()) {
				os << m_membership;
			}
			else{
				os.fill(' ');
				os << " N/A ";
			}
			os << " | ";
			os << m_date;
			os << " |";
		}
		else {
			os << type();
			os << '\t';
			os << m_libRef;
			os << '\t';
			os << m_shelfId;
			os << '\t';
			os << m_title;
			os << '\t';
			if (onLoan()) {
				os << m_membership;
			}
			else {
				os.fill(' ');
				os << " 0 ";
			}
			os << '\t';
			os << m_date;
		}
		return os;
	}
	istream& Publication::read(std::istream& istr)
	{	
		char title[255];
		char shelfId[5];
		int membership = 0;
		int libRef = -1;
		Date date;

		delete[] m_title;
		m_title = nullptr;
		strcpy(m_shelfId, "");
		m_membership = 0;
		m_libRef = -1;
		
		if (conIO(istr)) {
			cout << "Shelf No: ";
			
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1);
		
			if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}
			
			cout << "Title: ";
			istr.getline(title, 255);
			
			cout << "Date: ";
			istr >> date;
			libRef = -1;		
		}
		else {
			
			istr >> libRef;
			istr.ignore(1000, '\t'); 
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
			istr.getline(title, 255, '\t');
			istr >> membership;
			istr.ignore(1000, '\t'); 
			istr >> date;
		}
		if (date.validate()==false) {
			istr.setstate(ios::failbit);
		}
		if (istr.good() /*!istr.fail()*/) {
			if (title[0] != '\0') {
				delete[] m_title;
				m_title = nullptr;
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
				strcpy(m_shelfId, shelfId);
			}
			if (shelfId[0] != '\0') {
				//_shelfId[SENECA_SHELF_ID_LEN] = '\0';
				strcpy(m_shelfId, shelfId);
			}
			m_membership = membership;
			m_libRef = libRef;
			m_date = date;
		}
		return istr;
	}
	
	Publication::operator bool() const
	{
		return m_title != nullptr && m_title[0] != '\0' && m_shelfId[0] != '\0';
	}

		Publication::Publication(const Publication& p) {
			m_membership = 0;
			m_title = nullptr;
			m_shelfId[0] = '\0';
			if (this != &p) {
				delete[] m_title;
				m_title = new char[strlen(p.m_title) + 1];
				strcpy(m_title, p.m_title);
				strcpy(m_shelfId, p.m_shelfId);
				m_membership = p.m_membership;
				m_libRef = p.m_libRef;
				m_date = p.m_date;
			}
		}
		Publication& Publication::operator=(const Publication& p) {
			if (this != &p) {
				delete[] m_title;
				m_title = nullptr;
				if (p.m_title != nullptr) {
					m_title = new char[strlen(p.m_title) + 1];
					strcpy(m_title, p.m_title);
				}
				strcpy(m_shelfId, p.m_shelfId);
				m_membership = p.m_membership;
				m_libRef = p.m_libRef;
				m_date = p.m_date;
			}
			return *this;
		}

	Publication::~Publication()
	{	
		delete[] m_title;	
		m_title = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Publication& P)
	{
		return P.write(os);
	}
	std::istream& operator>>(std::istream& is, Publication& P) {
		return P.read(is);
	}

}