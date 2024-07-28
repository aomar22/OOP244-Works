#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H

#include <iostream>

namespace seneca {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& ios);
	std::istream& operator>>(std::istream& istr, Streamable& ios);
}
#endif //SENECA_STREAMABLE_H