#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Truck.h"
using namespace std;
namespace seneca {
	Truck::Truck()
	{
		setEmpty();
	}
	void Truck::setEmpty() {
		m_capacity = 0;
		m_currentCargoLoad = 0;
	}
	Truck::Truck(const char plateNum[], const int year, const double capacity, const char location[]) : MotorVehicle(plateNum, year)
	{  
		setEmpty();
		bool valid = plateNum[0] != '\0' && year != 0 && capacity != 0 && location[0] != '\0';
		if (valid) {
			m_capacity = capacity;
			m_currentCargoLoad = 0;
			moveTo(location);
		}
	}
	bool Truck::addCargo(double cargo) 
	{
		if (m_currentCargoLoad != m_capacity) {
			m_currentCargoLoad += cargo;
			if (m_currentCargoLoad < m_capacity) {
				return true;
			}
			else if(m_currentCargoLoad > m_capacity){
				m_currentCargoLoad = m_capacity;
				return true;
			}
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
			os << " | " << m_currentCargoLoad << "/" << m_capacity;
		return os;
	}
	std::istream& Truck::read(std::istream& is)
	{
		MotorVehicle::read(is);
		cout << "Capacity : ";
		is >> m_capacity;
		cout << "Cargo : ";
		is >> m_currentCargoLoad;
		return is;
	}
	
	std::istream& operator>>(std::istream& is, Truck& t)
	{
		return t.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const Truck& t)
	{
		return t.write(os);
	}

}


