#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "MotorVehicle.h"
namespace seneca {
    class Truck :public MotorVehicle {


        /*You can add any other private members in the class, as required by your
        design. Do not duplicate members from the base class!*/
        double m_capacity;
        //a capacity in kilograms as a floating-point number in double precision;
        // this is the maximum weight of the cargo the truck can carry.
      /*  the current cargo load(in kilograms) is a floating - point number
            in double precision; the load cannot exceed the capacity.*/

    public:
        Truck();
        Truck(char* plateNum, int year, double capacity, char location);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const; //query
        std::istream& read(std::istream& is);
        //Helper functions
        std::istream& operator>>(std::istream& is);
        std::ostream& operator<<(std::ostream& os);
    };
}
#endif // !TRUCK_H

