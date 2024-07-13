#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "MotorVehicle.h"
namespace seneca {    
        class Truck : public MotorVehicle {
            double m_capacity;
            double m_currentCargoLoad;
        public:
            Truck();
            Truck(const char plateNum[], const int year, const double capacity, const char location[]);
            void setEmpty();
            bool addCargo(double cargo);
            bool unloadCargo();
            std::ostream& write(std::ostream& os) const; //query
            std::istream& read(std::istream& is);
        };
        std::istream& operator>>(std::istream& is, Truck& t);
        std::ostream& operator<<(std::ostream& os, const Truck& t);
    
}
#endif // !TRUCK_H

