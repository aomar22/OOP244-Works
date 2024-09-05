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
#include "Book.h"
#include "Lib.h"

using namespace std;
namespace seneca {

    Book::Book(const Book& book):  m_author(nullptr) {
     
        if (this != &book) {
         //   delete[] m_author;
         //   m_author = nullptr;
            m_author = new char[strlen(book.m_author) + 1];
            strcpy(m_author, book.m_author);
        }  
    }
    Book& Book::operator=(const Book& book)
    {
        if (this != &book) {

            Publication::operator=(book);
            delete[] m_author;
            if (book.m_author != nullptr) {
                m_author = new char[strlen(book.m_author) + 1];
                strcpy(m_author, book.m_author);
            }
            else {
                m_author = nullptr;
            }
        }
        return *this;
    }

    Book::~Book()
    {
        delete[] m_author;
       // m_author = nullptr;
    }
    char Book::type() const
    {
        return 'B';
    }
    std::ostream& Book::write(std::ostream& os) const
    {
        Publication::write(os);
        if (conIO(os)) {
            
            os << ' ';    
            if (m_author && strlen(m_author) > SENECA_AUTHOR_WIDTH) {
                for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++) {
                    os << m_author[i];
                }   
               // os.write(m_author, SENECA_AUTHOR_WIDTH);
            }
            else {
                os.width(SENECA_AUTHOR_WIDTH);
                os.setf(ios::left);
                os << m_author;
            }        
           os << " |";
        }
        else {
            os << '\t';
            os << m_author;
        } 
        return os;
    }

    std::istream& Book::read(std::istream& istr)
    {
        char author[256 +1];
        Publication::read(istr);
        delete[] m_author;
        if (Publication::conIO(istr)) {
            istr.ignore(10000, '\n');
            cout << "Author: ";
            istr.getline(author, 257, '\n');
        }
        else {
            istr.ignore();
            istr.get(author, 257, '\n');
            
        }
        if (istr && strlen(author) > 0) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        } else {
            m_author = nullptr;
        }
        return istr;
    }
   
    void Book::set(int member_id)
    {
        Publication::set(member_id);
       Publication::resetDate();
    }
    Book::operator bool() const
    {
        return (Publication::operator bool() && m_author && m_author[0] != '\0');
    }
    std::ostream& operator<<(std::ostream& os, const Book& B)
    {
        return B.write(os);
    }
    std::istream& operator>>(std::istream& is, Book& B) {
        return B.read(is);
    }
}

