#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "Publication.h"
namespace seneca {
	class Book : public Publication {
		char* m_author{ nullptr };
	public:
		friend class Date;
		Book() : Publication(), m_author(nullptr) {};
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		//overrides:
		char type()const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;
	};
}

#endif