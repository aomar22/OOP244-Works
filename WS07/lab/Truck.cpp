#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Truck.h"
using namespace std;
using namespace seneca;
	Truck::Truck() 
	{

	}

	//Call the constructor from the base class and pass the license number and year to it.
	//Set the current cargo to 0 and move the truck to the address specified in the last parameter.
	Truck::Truck(char* plateNum, int year, double capacity, char location)
	{

	}

	//a mutator that adds to the attribute that stores the current
	//cargo load the weight specified as a parameter.Do not exceed the capacity!If the current
		//load has been changed, return true, otherwise return false.
	bool Truck::addCargo(double cargo)
	{
		return false;
	}

	// a mutator that unloads current cargo (sets the attribute to 0). If the 
	//current load has been changed, return true, otherwise, return false.
	bool Truck::unloadCargo()
	{
		return false;
	}

	//a query that inserts into os the content of the object in the format

	// | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO] / [CAPACITY]

	std::ostream& Truck::write(std::ostream& os) const
	{
		// TODO: insert return statement here
		return os;
	}

	//a mutator that reads from the stream in the data for the current object

	/*Built year : [USER TYPES HERE]
		License plate : [USER TYPES HERE]
		Current location : [USER TYPES HERE]
		Capacity : [USER TYPES HERE]
		Cargo : [USER TYPES HERE]
		*/
	std::istream& Truck::read(std::istream& is)
	{
		// TODO: insert return statement here
		return is;
	}

/*overload the insertion and extraction operators to insert a Truck into a stream and 
extract a Truck from a stream.These operators should call the write /
read member functions in the class Truck.*/
std::istream& Truck::operator>>(std::istream& is)
{
	// TODO: insert return statement here
	return is;
}

std::ostream& Truck::operator<<(std::ostream& os)
{
	// TODO: insert return statement here
	return os;
}


