#ifndef MotorVehicle_H
#define MotorVehicle_H
#include <iostream>
namespace seneca {
    class MotorVehicle {
        char m_plateNum[9];
        char m_location[64];
        int m_makeYear;
        void setEmpty();
    public:
        MotorVehicle();
        /* license plate number and the year when the vehicle was built.
        Set the location of the vehicle at Factory*/
     //   const char* getCurrentLocation();
        MotorVehicle(const char plate[], const int year);
      //  MotorVehicle(const char licencePlate[], int year, const char location[], double capacity);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os)const; //query
        std::istream& read(std::istream& is);
        friend  std::istream& operator>>(std::istream& is, MotorVehicle& mv);
        friend  std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv);
    };
}

#endif