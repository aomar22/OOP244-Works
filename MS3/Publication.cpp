#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"

using namespace std;
namespace seneca {

	Publication::Publication(): m_date(Date()) /*: Streamable()*/ {
		m_title = nullptr; //hold a dynamic title for the publication, null by default..
		m_shelfId[0] = {'\0'}; //Hold the location of the publication in the library
		m_membership = 0; //hold a 5-digit membership number of members of the library.
		m_libRef = -1;
		//m_date = Date();
	}
	void Publication::set(int member_id)
	{

		if (member_id > 10000 && member_id < 99999) {
			m_membership = member_id;
			/*m_membership = member_id;
			cout.width(5);
			cout.fill(0);
			cout << m_membership;*/
		}
		else if (member_id == 0) {
			m_membership = 0;
		}
	}
	void Publication::setRef(int value)
	{
		if (value > -1) { //**
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
		return m_membership > 0;
	}

	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		char* result = strstr(m_title, title);
		return result;
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
	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os)) {
			/*os << "         1         2         3         4         5         6         7 " << endl;
			os << "1234567890123456789012345678901234567890123456789012345678901234567890" << endl;*/
			os.width(SENECA_SHELF_ID_LEN);
			os << "| " << m_shelfId;
			os << " | ";
			/*os.setf(ios::left);*/
			//os.fill('.');
			os.width(SENECA_TITLE_WIDTH);
			if (strlen(m_title) > os.width(SENECA_TITLE_WIDTH)){
				 os.write(m_title, SENECA_TITLE_WIDTH);
			}
			else {
				os << os.setf(ios::left) << os.fill('.') << os.width(SENECA_TITLE_WIDTH) << m_title;
			}
			//os << m_title;
			os << " | ";
			os << m_membership;
			os << " | ";
			os << m_date << " |";
		}
		else {
			os << type() << '\t';
			os << m_libRef << '\t';
			os.width(SENECA_SHELF_ID_LEN);
			os << m_shelfId << '\t';
			os.width(SENECA_TITLE_WIDTH);
			os << m_title << '\t';
			os << m_membership << '\t';
			os << m_date;
		}
		return os;
	}
	//void Publication::setEmpty() {

	//	m_title = nullptr; //hold a dynamic title for the publication, null by default..
	//	m_shelfId[0] = {'\0'}; //Hold the location of the publication in the library
	//	m_membership = 0; //hold a 5-digit membership number of members of the library.
	//	m_libRef = -1;
	//	m_date = Date();
	//}
	istream& Publication::read(istream& istr)
	{
		char title[255] = {};
		char shelfId[SENECA_SHELF_ID_LEN + 1] = {};
		int membership = 0;
		int libRef = -1;
		Date date;

		if (m_title != nullptr) {
			delete[] m_title;
		}
		m_title = nullptr;

		//setEmpty();
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\n');
			if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.getline(title, 255);
			cout << "Date: ";
			istr >> date;
			//date.read(istr);
			/*istr >> date;*/

			//libRef = -1;
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
		if (date.validate() == false) {
			istr.setstate(ios::failbit);
		}
		if (istr.good()) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return istr;
	}
	Publication::operator bool() const
	{
		return m_title != nullptr && m_title[0] != '\0' && m_shelfId[0] != '\0';
	}

	Publication::Publication(const Publication& p)
	{
		//setEmpty();
		m_date = Date();
		m_membership = 0;
		m_libRef = -1;
		m_shelfId[0] = '\0';
		if (this != &p) {
			//	*this = p;

			delete[] m_title;
			m_title = nullptr;
			//	if (p.m_title != nullptr) {
			m_title = new char[strlen(p.m_title) + 1];
			strcpy(m_title, p.m_title);
			//}

			strcpy(m_shelfId, p.m_shelfId);
			m_membership = p.m_membership;
			m_libRef = p.m_libRef;
			m_date = p.m_date;
			/*if (m_title != nullptr) {
				m_title = new char[SENECA_TITLE_WIDTH + 1];
				strncpy(m_title, p.m_title, SENECA_TITLE_WIDTH);
			}
		}
		else {
				m_title = nullptr;
		}*/
		}
		else {
			m_title = nullptr;
		}

	}

	Publication& Publication::operator=(const Publication& p)
	{
		if (this != &p) {
			delete[] m_title;
			m_title = nullptr;
			/*m_membership = p.m_membership;
			m_libRef = p.m_libRef;
			m_date = p.m_date;
			m_shelfId[SENECA_SHELF_ID_LEN] = '\0';*/

			if (p.m_title != nullptr) {
				delete[] m_title;
				if (p.m_title != nullptr && p.m_title[0] != '\0') {
					m_title = new char[strlen(p.m_title) + 1];
					//for (int i = 0; i < SENECA_TITLE_WIDTH; i++) {
					strcpy(m_title, p.m_title);
					//m_title[i] = p.m_title[i];
					//m_title = nullptr;
				//}
				}
				strcpy(m_shelfId, p.m_shelfId);
				m_membership = p.m_membership;
				m_libRef = p.m_libRef;
				m_date = p.m_date;

			}
			else {
				m_title = nullptr;

			}
		}
		return *this;
	}

	Publication::~Publication()
	{
		
			delete[] m_title;
		
	}

}