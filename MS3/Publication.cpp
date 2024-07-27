#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"

using namespace std;

namespace seneca {

    Publication::Publication() : m_title(nullptr), m_membership(0), m_libRef(-1), m_date(Date()) {
        m_shelfId[0] = '\0';
    }

    void Publication::set(int member_id) {
        if (member_id > 10000 && member_id < 99999) {
            m_membership = member_id;
        }
        else /*if (member_id == 0)*/ {
            m_membership = 0;
        }
    }

    void Publication::setRef(int value) {
        m_libRef = (value > -1) ? value : -1;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership > 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios& ios) const {
        return (&ios == &cin || &ios == &cout);
    }

    ostream& Publication::write(ostream& os) const {
        if (conIO(os)) {
            os << "         1         2         3         4         5         6         7 " << endl;
            os << "1234567890123456789012345678901234567890123456789012345678901234567890" << endl;
            os.width(SENECA_SHELF_ID_LEN);
            os << "| " << m_shelfId;
            os << " | ";
            os.width(SENECA_TITLE_WIDTH);
            os.setf(ios::left);
            os.fill('.');
            os << (m_title ? m_title : "") << " | ";
            os << m_membership << " | " << m_date << " |";
        }
        else {
            os << type() << '\t'
                << m_libRef << '\t'
                << m_shelfId << '\t'
                << (m_title ? m_title : "") << '\t'
                << m_membership << '\t'
                << m_date;
        }
        return os;
    }

    void Publication::setEmpty() {
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0]={};
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();
    }

    istream& Publication::read(istream& istr) {
        char title[255] = {};
        char shelfId[SENECA_SHELF_ID_LEN + 1] = {};
        int membership = 0;
        int libRef = -1;
        Date date;
      //  setEmpty();
        if (conIO(istr)) {
            cout << "Shelf No: ";
            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\n');
            if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
                istr.setstate(ios::failbit);
                return istr;
            }
            cout << "Title: ";
            istr.getline(title, 255);
            cout << "Date: ";
            istr >> date;
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
        if (!date.validate()) {
            istr.setstate(ios::failbit);
            return istr;
        }
        if (istr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            m_membership = membership;
            m_date = date;
            m_libRef = libRef;
        }
        return istr;
    }
    Publication::operator bool() const {
        return m_title != nullptr && m_title[0] != '\0' && m_shelfId[0] != '\0';
    }
    Publication::Publication(const Publication& p) : m_title(nullptr) {
        if (p.m_title) {
            m_title = new char[strlen(p.m_title) + 1];
            strcpy(m_title, p.m_title);
        }
        strcpy(m_shelfId, p.m_shelfId);
        m_membership = p.m_membership;
        m_libRef = p.m_libRef;
        m_date = p.m_date;
    }
    Publication& Publication::operator=(const Publication& p) {
        if (this != &p) {
            delete[] m_title;
            m_title = nullptr;
            if (p.m_title) {
                m_title = new char[strlen(p.m_title) + 1];
                strcpy(m_title, p.m_title);
            }
            m_shelfId[0] = { '\0' };
            if (strlen(p.m_shelfId) <= SENECA_SHELF_ID_LEN) {
                strncpy(m_shelfId, p.m_shelfId, strlen(p.m_shelfId));
            }
            m_membership = p.m_membership;
            m_libRef = p.m_libRef;
            m_date = p.m_date;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }
}
