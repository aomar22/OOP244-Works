#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Truck.h"
using namespace std;
namespace seneca {
	Truck::Truck()
	{
		m_capacity = 0;
        m_currentCargoLoad = 0;
	}
	Truck::Truck(const char plateNum,const int year, const double capacity, const char location) : MotorVehicle(plateNum, year)
	{
		m_capacity = capacity;
		m_currenctCargoLoad = 0;
		moveTo(location);
	}
	bool Truck::addCargo(double cargo) 
	{
		double newCargo = m_currentCargoLoad + cargo;
		if (newCargo <= m_capacity) {
			m_currentCargoLoad = newCargo;
			return true;
		}
		return false;
	}
	bool Truck::unloadCargo()
	{
		if (m_currentCargoLoad != 0) {
			m_currentCargoLoad = 0;
			return true;
		}
		return false;
	}

	std::ostream& Truck::write(std::ostream& os) const
	{
		    MotorVehicle::write(os);
			os << "|" << m_currentCargoLoad << "/" << m_capacity;
		return os;
	}
	std::istream& Truck::read(std::istream& is)
	{
		MotorVehicle::read(is);
		cout << "Capacity : ";
		is >> m_capacity;
		cout << endl;
		cout << "Cargo : ";
		is >> m_currentCargoLoad;
		cout << endl;
		return is;
	}
	std::istream& Truck::operator>>(std::istream& is, Truck& t) 
	{
		return t.read(is);
	}

	std::ostream& Truck::operator<<(std::ostream& os, const Truck& t)
	{
		return t.write(os);
	}
	
}


