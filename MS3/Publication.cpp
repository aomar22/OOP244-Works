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

	Publication::Publication(): Streamable(), m_date(Date()) {
		m_title = nullptr; //hold a dynamic title for the publication, null by default..
		m_shelfId[0] = {'\0'}; //Hold the location of the publication in the library
		m_membership = 0; //hold a 5-digit membership number of members of the library.
		m_libRef = -1;
	}
	void Publication::set(int member_id)
	{
		if (member_id > 9999 && member_id < 99999) {
			m_membership = member_id;
		}
		else{
			m_membership = 0;
		}
	}
	void Publication::setRef(int value)
	{
		if (value < 0) { //**
			m_libRef = 0;
		}
		else {
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
		if (strstr(m_title, title)) {
			return true;
		}
		else {
			return false;
		}
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
		if (&io == &cin || &io == &cout) {
			return true;
		}
		else {
			return false;
		}
	}
	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os)) {
			os.setf(ios::left);
			os.fill('.');

			os << "| ";
			os.width(SENECA_SHELF_ID_LEN);
			os << m_shelfId;

			os << " | ";
			os.width(SENECA_TITLE_WIDTH);
			os << m_title;
			os << " | ";

			if (m_membership != 0) {
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | ";

			if (!m_date.errCode()) {
				os << m_date;
			}
			else {
				os << " N/A ";
			}
			os << " |";

			os.fill('.');
			os.unsetf(ios::left);
			return os;
		}
		else {
			os << type() << "\t";
			os << m_libRef;
			os << "\t";
			os << m_shelfId;
			os << "\t";
			os << m_title;
			os << "\t";
			os << m_membership;
			os << "\t";
			os << m_date;

			return os;
		}
	}
	istream& Publication::read(istream& istr)
	{
	char title[255 + 1]{};
	char shelfId[SENECA_SHELF_ID_LEN + 1]{};
	int membership = 0;
	int libRef = -1;
	Date date;

	// Clean up existing resources
	delete[] m_title;
	m_title = nullptr;

	// Reset class members
	m_shelfId[0] = '\0';
	m_membership = 0;
	m_libRef = -1;
	resetDate();

	if (conIO(istr)) {
		// Interactive input
		cout << "Shelf No: ";
		istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\n');
		if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
			istr.setstate(ios::failbit);
		}

		cout << "Title: ";
		istr.getline(title, 255);

		cout << "Date: ";
		istr >> date;
		if (!istr) {
			istr.setstate(ios::failbit);
		}

		// Clear newline character remaining in the buffer
		istr.ignore(1000, '\n');
	}
	else {
		// Non-interactive input
		istr >> libRef;
		istr.ignore(); // Ignore the delimiter after libRef
		istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
		istr.getline(title, 255, '\t');
		istr >> membership;
		istr.ignore(); // Ignore the delimiter after membership
		istr >> date;
		
	}

	// Validate date and handle errors
	if (!date.validate()) {
		istr.setstate(ios::failbit);
	}

	// If input was successful, update the object
	if (istr) {
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		strcpy(m_shelfId, shelfId);
		m_membership = membership;
		m_libRef = libRef;
		m_date = date;
	}

	return istr;
}
	Publication::operator bool() const
	{
		return m_title != nullptr && m_shelfId[0] != '\0';
	}

	Publication::Publication(const Publication& p)
	{
		//setEmpty();
		m_title = nullptr;
		m_date = Date();
		m_membership = 0;
		m_libRef = -1;
		m_shelfId[0] = '\0';
		if (this != &p) {
			//	*this = p;

			//delete[] m_title;
			m_title = nullptr;
				if (p.m_title != nullptr) {
			m_title = new char[strlen(p.m_title) + 1];
			strcpy(m_title, p.m_title);
			}

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
		/*else {
			m_title = nullptr;
		}*/

	}

	Publication& Publication::operator=(const Publication& p)
	{
		if (this != &p) {
			m_membership = p.m_membership;
			m_libRef = p.m_libRef;
			m_date = p.m_date;
			strncpy(m_shelfId, p.m_shelfId, SENECA_SHELF_ID_LEN);
				m_shelfId[4] = '\0';

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
				else {
					m_title = nullptr;
				}
				/*strcpy(m_shelfId, p.m_shelfId);
				m_membership = p.m_membership;
				m_libRef = p.m_libRef;
				m_date = p.m_date;

			}
			else {
				m_title = nullptr;*/

			}
		}
		return *this;
	}

	Publication::~Publication()
	{
		
			delete[] m_title;
		
	}

}