/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 13th, 2024.
  Reason of Re-submitting: Adding citation
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
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
        MotorVehicle(const char plate[], const int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os)const; //query
        std::istream& read(std::istream& is);
        friend  std::istream& operator>>(std::istream& is, MotorVehicle& mv);
        friend  std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv);
    };
}

#endif