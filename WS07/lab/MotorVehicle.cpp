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
	MotorVehicle::MotorVehicle(const char plate[],const int year)
	{
		setEmpty();
		if (m_plateNum && m_location) {
			strncpy(m_plateNum, plate, strlen(plate)+1);
			m_plateNum[strlen(plate) + 1] = '\0';
			m_makeYear = year;
			strcpy(m_location, "Factory");
		}
	}
	void MotorVehicle::moveTo(const char* address)
	{
		char* currentAddress = m_location;
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_plateNum;
			cout << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << currentAddress << " ---> ";

			if (strcmp(m_location, address) != 0) {
				strcpy(m_location, address);
			}
			cout.width(20);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_location;
			cout.fill(' ');
			cout << "|" << endl;
		
	}
	ostream& MotorVehicle::write(ostream& os) const
	{ 
		os << "| " << m_makeYear << " | " << m_plateNum << " | " << m_location;
		return os;
	}
	std::istream& MotorVehicle::read(std::istream& is)
	{
		cout << "Built year : ";
		is >> m_makeYear;
		cout << "License plate : ";
		is >> m_plateNum;
		cout << "Current location : ";
		is >> m_location;
		return is;
	}
	std::istream& operator>>(std::istream& is, MotorVehicle& mv)
	{
		return mv.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv)
	{
		return mv.write(os);
	}
}
