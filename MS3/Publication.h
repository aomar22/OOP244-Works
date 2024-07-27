#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
namespace seneca {

	class Publication : public Streamable {
		//Attributes:
	
		char* m_title; //hold a dynamic title for the publication, null by default..
		char* m_shelfId; //Hold the location of the publication in the library
		int m_membership; //hold a 5-digit membership number of members of the library.
		int m_libRef; //used internally to uniquely identify each publication in the system.
		Date m_date; //by default, is set to the current date
	public:
		Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		void setEmpty();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		bool conIO(std::ios& ios)const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		//The Rule of three
		Publication(const Publication& p);
		Publication& operator=(const Publication& p);
		~Publication();

	};

	/*virtual std::ostream& write(std::ostream& os)const = 0;
	virtual std::istream& read(std::istream& istr) = 0;

	virtual bool conIO(std::iostream& ios)const = 0;
	virtual operator bool()const = 0;
*/


}
#endif //SENECA_PUBLICATION_H