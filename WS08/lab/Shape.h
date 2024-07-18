#ifndef SHAPE_H
#define SHAPE_H
namespace seneca {
	/*Create the following two Pure virtual functions:

    In C++, a Pure virtual function is a virtual function
	that has no implementation in the base class. It is declared
	by setting its prototype to zero (= 0;) in the class declaration.
	This makes the class an interface, which cannot be instantiated. \
	Any derived class must provide an implementation for this function, unless the derived class is also abstract.
*/
	class Shape {
		//Methods
	public:
		/*Create a default virtual destructor for the shape interface.

			To create a default virtual destructor for a class, you would declare it in the class definition 
			using virtual ~ClassName() = default; .This tells the compiler to generate a default destructor.
			This guarantees that any dynamically allocated derived class from the Shape interface pointed 
			by a Shape pointer will be removed properly from memory when deleted.No implementation is 
			required in this case, as the compiler automatically generates it.This is a good practice in object 
			- oriented programming in C++.*/

		virtual ~Shape() = default; //no implementation is needed
		virtual void draw(std::ostream& os) const = 0;//This pure virtual function can not modify the current object.
		virtual void getSpecs(std::istream& is) = 0; //Returns void and receives a reference to istream as an argument
		//Helper functions
		std::ostream& operator<<(std::ostream& os);
		std::istream& operator>>(std::istream& is);
	};
}

#endif //SHAPE_H