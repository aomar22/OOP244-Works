#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#include "Date.h"
/*The publication class is a general encapsulation of any periodic publication. Publication inherits from Streamable.

    Later by adding an author to the descendant of the Publication class we will encapsulate a Book for the system.
*/
namespace seneca {

	class Publication : public Streamable {
		//Attributes:
		char* m_title[255 +1]{ Null }; //hold a dynamic title for the publication, null by default..
		char m_shelfId[4 + 1]{ }; //Hold the location of the publication in the library
		int m_membership{ 0 }; //hold a 5-digit membership number of members of the library.
		int m_libRef{ -1 }; //used internally to uniquely identify each publication in the system.
		/*In periodical publications, this date is used for the publish date of the item.

		In Books, this date is used to keep the date on which the book was borrowed by the member.
			*/
		Date m_date; //by default, is set to the current date
		Publication();
	public:

		//Methods:
		//Modifiers:
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		//Quiries:
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.

		//Streamable pure virtual function implementations:
		bool conIO(ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		//The Rule of three
		Publication(const Publication& p);
		Publication& operator=(const Publication& p);
		~Publication();

	};





}
/*


m_date

A Date object.

In periodical publications, this date is used for the publish date of the item.

In Books, this date is used to keep the date on which the book was borrowed by the member.

The Date, by default, is set to the current date.
Constructor (default)

Sets all the attributes to their default values*/



#endif //SENECA_PUBLICATION_H