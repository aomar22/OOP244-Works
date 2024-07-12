#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MotorVehicle.h"
using namespace std;
using namespace seneca;

	MotorVehicle::MotorVehicle()
	{

	}
	 /*a custom constructor that receives as parameters the license plate number
	and the year when the vehicle was built.Set the location of the vehicle at Factory.
		Assume all data is valid.*/
	MotorVehicle::MotorVehicle(char* plateNum, int year, char location)
	{
	}

	/*moves the vehicle to the new address if the new 
address is different from the current address. Prints to the screen the message

|[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>

where

    the license plate is a field of 8 characters aligned to the right
    current address is a field of 20 characters aligned to the right
    new address is a field of 20 characters aligned to left*/
	void MotorVehicle::moveTo(const char* address)
	{
	}

	/* a query that inserts into os the content of the object in the format

| [YEAR] | [PLATE] | [ADDRESS]*/
	ostream& MotorVehicle::write(ostream& os) const
	{
		// TODO: insert return statement here
		return os;
	}

		/*a mutator that reads from the stream in the data for the current object

		Built year : [USER TYPES HERE]
		License plate : [USER TYPES HERE]
		Current location : [USER TYPES HERE]*/
	std::istream& MotorVehicle::read(std::istream& is)
	{
		// TODO: insert return statement here
		return is;
	}

	/*overload the insertion and extraction operators to insert a MotorVehicle into
a stream and extract a MotorVehicle from a stream.These operators should
call the write / read member functions in the class MotorVehicle.*/


/*Helper Functions

    overload the insertion and extraction operators to insert a MotorVehicle 
	into a stream and extract a MotorVehicle from a stream. These operators 
	should call the write/read member functions in the class MotorVehicle.
*/

	ostream& seneca::operator<<(std::ostream& os, MotorVehicle& mv)
	{
	// TODO: insert return statement here
		return os;
	}

	std::istream& seneca::operator>>(std::istream& is, MotorVehicle& mv)
	{
	 // TODO: insert return statement here
		return is;
	}

