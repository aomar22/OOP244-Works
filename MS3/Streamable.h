#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H
//Abstract Base Class

namespace seneca {
	class Streamable {
		//pure virtual functions
		virtual std::ostream& write(std::ostream& ostr) = 0;
		virtual std::istream& read(std::istream& istr)const = 0;

		virtual bool conIO(std::iostream& ios) = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();
	};
	//Helper functions:
	std::istream& operator>>(std::istream& is, const Streamable& str);
	std::ostream& operator<<(std::ostream& os, const Streamable& str);
}

/*write pure virtual function

This method is not capable of modifying the Streamable object. write receives and returns a reference of an ostream object.

Functions overriding this function will write into an ostream object.
read pure virtual function

read receives and returns a reference of an istream object.

Functions overriding this function will read from an istream object.
conIO

This method is not capable of modifying the Streamable object. conIo receives a reference of an ios object and returns a Boolean.

Functions overriding this function will determine if the incoming ios object is a console IO object or not.
Boolean conversion operator overload (pure virtual)

Boolean conversion overloads of this method will return if the Streamable object is in a valid state or not.
destructor

Add an empty virtual destructor to this interface to guarantee that the descendants of the Streamable are removed from memory with no leak.
Helper Operator Overloads
Insertion operator overload

Overload the insertion operator so a constant object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state. Otherwise, the function will quietly ignore the insertion action.
Extraction operator overload

Overload the extraction operator so an object of type Streamable can be read from an istream object.*/



#endif //SENECA_STREAMABLE_H