/*Final Project Milestone 4
Module: Book
Filename : Book.cpp
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
#include <iomanip>
#include "Book.h"
#include "Lib.h"

using namespace std;
namespace seneca {

    Book::Book(const Book& book) : Publication(book), m_author(nullptr)  {
        m_author = nullptr;
        if (this != &book) {

            delete[] m_author;
            m_author = nullptr;
            m_author = new char[strlen(book.m_author) + 1];
            strcpy(m_author, book.m_author);
        }
    }

    Book& Book::operator=(const Book& book)
    {
        if (this != &book) {
            delete[] m_author;
           // m_author = nullptr;
            if (book.m_author != nullptr) {
                m_author = new char[strlen(book.m_author) + 1];
                strcpy(m_author, book.m_author);
            }
            else {
                m_author = nullptr;
            }
            Publication::operator=(book);
        }
        return *this;
    }

    Book::~Book()
    {
        delete[] m_author;
    }

    char Book::type() const
    {
        return 'B';
    }

    std::ostream& Book::write(std::ostream& os) const
    {
        Publication::write(os);
        if (Publication::conIO(os)) {
            os << ' ';
            if (strlen(m_author) > SENECA_AUTHOR_WIDTH) {
                for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++) {
                    os << m_author[i];
                }
                os << " |";
            }
           
        }
        else {
            os << '\t';
            os << m_author;
            return os;
        }
        return os;
    }

    std::istream& Book::read(std::istream& istr)
    {
        char author[256];
        Publication::read(istr);
        delete[] m_author;
        if (Publication::conIO(istr)) {
            istr.ignore(1000, '\n');
            cout << "Author: ";
            istr.getline(author, 257);
        }
        else {
            istr.ignore(1000, '\t');
            istr.getline(author, 257);
        }
        if (!istr.fail()) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }
        return istr;
    }
    void Book::set(int member_id)
    {
        Publication::set(member_id);
        resetDate();
    }
    Book::operator bool() const
    {
        return m_author != nullptr && Publication::operator bool();
    }
}

