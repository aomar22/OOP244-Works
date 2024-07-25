#include <iostream>
#include "Publication.h"




Publication() {
	har* m_title[255 + 1] = { Null }; //hold a dynamic title for the publication, null by default..
	char m_shelfId[4 + 1] = { '\0' }; //Hold the location of the publication in the library
	int m_membership = 0; //hold a 5-digit membership number of members of the library.
	int m_libRef = -1; //used internally to uniquely identify each publication in the system.
	/*In periodical publications, this date is used for the publish date of the item.

	In Books, this date is used to keep the date on which the book was borrowed by the member.
		*/
	Date m_date;
}