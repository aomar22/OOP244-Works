#include <iostream>
#include "Publication.h"
#include "Date.h"


using namespace std;
namespace seneca {

	Publication::Publication() {
		 m_title[0] = Nullptr; //hold a dynamic title for the publication, null by default..
		 m_shelfId[0] = { '\0' }; //Hold the location of the publication in the library
		 m_membership = 0; //hold a 5-digit membership number of members of the library.
		 m_libRef = -1; //used internally to uniquely identify each publication in the system.
		/*In periodical publications, this date is used for the publish date of the item.

		In Books, this date is used to keep the date on which the book was borrowed by the member.
			*/
		m_date = ;
	}
	virtual char type()const {
		return 'P';
	}
	bool onLoan()const {
		return m_membership != 0;
	}
	//Returns true is the publication is checkout (membership is non-zero)
}