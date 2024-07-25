#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"


using namespace std;
namespace seneca {

	Publication::Publication() : m_date(Date()) {
		m_title[0] = '\0'; //hold a dynamic title for the publication, null by default..
		m_shelfId[0] = { '\0' }; //Hold the location of the publication in the library
		m_membership = 0; //hold a 5-digit membership number of members of the library.
		m_libRef = -1;

	}
	//used internally to uniquely identify each publication in the system.
	   /*In periodical publications, this date is used for the publish date of the item.

	   In Books, this date is used to keep the date on which the book was borrowed by the member.
		   */
	void Publication::set(int member_id)
	{
		if (member_id == 0) {
			m_membership = 0;
		}
		else if (member_id > 10000 && member_id < 99999) {
			m_membership = member_id;
			/*m_membership = member_id;
			cout.width(5);
			cout.fill(0);
			cout << m_membership;*/
		}
	}
	void Publication::setRef(int value)
	{
		m_libRef = value;
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
		char* result = strstr(m_title, title);
		if (result) {
			return true;
		}
		return false;
	}
	Publication::operator const char* () const
	{
		return m_title;
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const
	{
		return (&io == &cin || &io == &cout);
	}
	std::ostream& Publication::write(std::ostream& os) const
	{
		if (conIO(os)) {
			os << "         1         2         3         4         5         6         7 " << endl;
			os << "1234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			os << "| " << m_shelfId;
			os << " | ";
			os.setf(ios::left);
			os.fill('.');
			os << m_title;
			os << " | ";
			os << m_membership;
			os << " | ";
			os << m_date << " |";
		}
		else {
			os << type() << '\t';
			os << m_libRef << '\t';
			os << m_shelfId << '\t';
			os << m_title << '\t';
			os << m_membership << '\t';
			os << m_date;
		}
		return os;
	}
	void Publication::setEmpty() {

		m_title[0] = '\0'; //hold a dynamic title for the publication, null by default..
		m_shelfId[0] = { '\0' }; //Hold the location of the publication in the library
		m_membership = 0; //hold a 5-digit membership number of members of the library.
		m_libRef = -1;
		m_date = Date();
	}
	std::istream& Publication::read(std::istream& istr)
	{
		/*char* m_title; //hold a dynamic title for the publication, null by default..
		char m_shelfId[4 + 1]{ }; //Hold the location of the publication in the library
		int m_membership{ 0 }; //hold a 5-digit membership number of members of the library.
		int m_libRef{ -1 };*/
		char* title = nullptr;
		char* shelfId = nullptr;
		int membership = 0;
		int libRef = -1;
		Date date;
		delete[] m_title;
		setEmpty();
		if (conIO(istr) && shelfId != nullptr) {
			cout << "Shelf No: ";
			for (int i = 0; i < SENECA_SHELF_ID_LEN; i++) {
				istr >> shelfId[i];
				if (i != SENECA_SHELF_ID_LEN) {
					istr.fail();
				}
				//cout << endl;
			}
			cout << "Title: ";
			istr >> title;

			cout << "Date: ";
			date.read(istr);
			/*istr >> date;*/

			libRef = -1;
		}
		else {
			istr >> libRef;
			istr.ignore('\t');
			istr >> shelfId;
			istr.ignore('\t');
			istr >> title;
			istr.ignore('\t');
			istr >> membership;
			istr.ignore('\t');
			date.read(istr);
		}
		if (!m_date) {
			istr.fail();
		}
		if (istr) {
			m_title = new char[SENECA_TITLE_WIDTH + 1];
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
		if (m_title != nullptr || m_shelfId != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	Publication::Publication(const Publication& p)
	{
		if (p) {
			strncpy(m_shelfId, p.m_shelfId, SENECA_SHELF_ID_LEN);
			m_membership = p.m_membership;
			m_libRef = p.m_libRef;
			m_date = p.m_date;
			if (m_title != nullptr) {
				m_title = new char[SENECA_TITLE_WIDTH + 1];
					strncpy(m_title, p.m_title, SENECA_TITLE_WIDTH);
			}
			else {
				m_title = nullptr;
			}
			

		}
	}

	Publication& Publication::operator=(const Publication& p)
	{
		if (this != &p) {
			m_membership = p.m_membership;
			m_libRef = p.m_libRef;
			m_date = p.m_date;

			delete[] m_title;
			if (p.m_title != nullptr) {
				m_title = new char[SENECA_TITLE_WIDTH + 1];
				for (int i = 0; i < SENECA_TITLE_WIDTH; i++) {
					m_title[i] = p.m_title[i];
					m_title = nullptr;
				}
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

	/*After the process of reading is done if istr is in a valid state:

    Dynamically store the title in the title attribute
    copy the shelf ID into the shelfId attribute
    set the membership
    set the date
    set the libRef attribute

At the end return the istr argument.*/
	/*Read all the values in local variables before setting the attributes to any values.

First, clear all the attributes by freeing the memory and setting everything to their default values.

Then, if the istr argument is a console IO object (use conIO()) read the attributes as follows:

    prompt: "Shelf No: "
    read the shelf number up to its limit (see Lib.h).
    if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
    prompt: "Title: "
    read the title
    prompt: "Date: "
    read the date

    in this case the libRef value is left with its default value.

Otherwise, assume the reading begins with the libRef attribute as if the type 'P' is not in the file.

    read the libRef number
    skip the tab
    read the shelf number
    skip the tab
    read the title
    skip the tab
    read the membership
    skip the tab
    read the date

Either way, if the date is in an invalid state set the istr to a fail state manually

After the process of reading is done if istr is in a valid state:

    Dynamically store the title in the title attribute
    copy the shelf ID into the shelfId attribute
    set the membership
    set the date
    set the libRef attribute

At the end return the istr argument.*/
}