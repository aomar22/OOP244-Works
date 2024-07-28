#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Book.h"

using namespace std;
namespace seneca {

    Book::Book(const Book& book) {
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
            delete m_author;
            m_author = nullptr;
            if (book.m_author != nullptr) {
                m_author = new char[strlen(book.m_author) + 1];
                strcpy(m_author, book.m_author);
            }
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
        if (conIO(os)) {
            os << ' ';
            if (strlen(m_author) > SENECA_AUTHOR_WIDTH) {
                for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++) {
                    os << m_author[i];
                }
            }
            os << " |";
        }
        else if (!conIO(os)) {
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
        if (conIO(istr)) {
            istr.ignore('\n');
            cout << "Author: ";
            istr.getline(author, 257);
        }
        else {
            istr.ignore('\t');
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
//    /*return true if the author's name exists and is not empty and the base class's operator bool() has returned true.*/
//    /*invoke the set of the base class to set the member id
//    reset the date to the current date.*/
//    /*Read the author name in local variables before setting the attribute to any value.
//(to make it easier let us assume the author's name can not be more than 256 characters)
//
//    First, invoke the read of the Base class.
//    Free the memory held for the author's name
//    If the incoming argument is a console IO object
//        ignore one character (skip the '\n')
//        prompt "Author: "
//        read the author's name
//    If the incoming argument is not a console IO object
//        ignore the tab character
//        read the author's name
//
//Then if the incoming istream object is not in a fail state,
//dynamically hold the author's name in the char pointer attribute of the book class.
//
//At the end return the incoming istream object.*/
//        
//        /*First, it will invoke the write of its Base class.
//        If the incoming argument is a console IO object.
//            writes a single space
//            writes the author's name in SENECA_AUTHOR_WIDTH spaces. If the author's name is longer than 
//            the SENECA_AUTHOR_WIDTH value, it will cut it short and write exactly the SENECA_AUTHOR_WIDTH 
//            characters.Note that this should not modify the author's name.
//            writes " |"
//            If the incoming argument is not a console IO object
//            writes a tab character '\t'
//            writes the author's name
//            returns the incoming ostream.*/
//    
//
//}
///*The Book class implementation
//
//The Book class is derived from the Publication class. A book is a publication with an "Author name".
//
//The book class only has one attribute which is a pointer to a character to hold an author's name Dynamically.
//Construction
//
//A book is created empty by default, in a safe empty state.
//The rule of three
//
//Implement what is needed to comply with the rule of three so a book can safely be copied or assigned to another book.
//Methods
//
//The book class overrides the following virtual methods and type conversion operator.
//
//    type
//    write
//    read
//    set
//    operator bool()
//
//Method implementations:
//type method
//
//Returns the character "B".
//write method
//
//    First, it will invoke the write of its Base class.
//    If the incoming argument is a console IO object.
//        writes a single space
//        writes the author's name in SENECA_AUTHOR_WIDTH spaces. If the author's name is longer than the SENECA_AUTHOR_WIDTH value, it will cut it short and write exactly the SENECA_AUTHOR_WIDTH characters. Note that this should not modify the author's name.
//        writes " |"
//    If the incoming argument is not a console IO object
//        writes a tab character '\t'
//        writes the author's name
//    returns the incoming ostream.
//
//Read
//
//
//set
//
//    
//
//operator bool()
//
