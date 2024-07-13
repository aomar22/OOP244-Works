#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "MotorVehicle.h"
using namespace std;
namespace seneca {
	
	MotorVehicle::MotorVehicle()
	{
		setEmpty();

	}

	void MotorVehicle::setEmpty() {
		m_plateNum[0] = '\0';
		m_location[0] = '\0';
		m_makeYear = 0;
	}
	/*a custom constructor that receives as parameters the license plate number
   and the year when the vehicle was built.Set the location of the vehicle at Factory.
	   Assume all data is valid.*/

	MotorVehicle::MotorVehicle(const char plate[],const int year)
	{
		setEmpty();
		if (m_plateNum && m_location) {
			strncpy(m_plateNum, plate, 10);
			m_plateNum[10] = '\0';
			m_makeYear = year;
			strncpy(m_location, "Factory", strlen("Factory") + 1);
			m_location[strlen("Factory")] = '\0';
		}

	}

	/*MotorVehicle::MotorVehicle(const char plateNum[], int year, const char location[], double capacity)
	{
		setEmpty();
		if (m_plateNum && m_location) {
			strncpy(m_plateNum, plateNum, 10);
			m_plateNum[10] = '\0';
			m_makeYear = year;
			strncpy(m_location, location, strlen(location) + 1);
			m_location[strlen(location)] = '\0';
		}
	}*/

	/*moves the vehicle to the new address if the new
address is different from the current address. Prints to the screen the message

|[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>

where

	the license plate is a field of 8 characters aligned to the right
	current address is a field of 20 characters aligned to the right
	new address is a field of 20 characters aligned to left*/
	void MotorVehicle::moveTo(const char* address)
	{
		char newAddress[65] = { '\0' };
		if (strcmp(m_location, address) != 0) {
			strcpy(newAddress, address);
			cout << "|" << m_plateNum << "|" << m_location << "|" << "--->" << newAddress << endl;
		}
	}

	/* a query that inserts into os the content of the object in the format

| [YEAR] | [PLATE] | [ADDRESS]*/
	ostream& MotorVehicle::write(ostream& os) const
	{
		os << "|" << m_makeYear << "|" << m_plateNum << "|" << m_location;
		return os;
	}

	/*a mutator that reads from the stream in the data for the current object

	Built year : [USER TYPES HERE]
	License plate : [USER TYPES HERE]
	Current location : [USER TYPES HERE]*/
	std::istream& MotorVehicle::read(std::istream& is)
	{
		cout << "Built year : ";
		is >> this->m_makeYear;
		cout << endl;
		cout << "License plate : ";
		is >> this->m_plateNum;
		cout << endl;
		cout << "Current location : ";
		is >> this->m_location;
		cout << endl;

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




	std::istream& operator>>(std::istream& is, MotorVehicle& mv)
	{
		return mv.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv)
	{
		return mv.write(os);
	}
}
