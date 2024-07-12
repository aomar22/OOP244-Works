#ifndef MotorVehicle_H
#define MotorVehicle_H
namespace seneca {
    class MotorVehicle {
        char m_plateNum[9];
        char m_location[64];
        int m_madeYear;
    public:
        MotorVehicle();
        MotorVehicle(char* plateNum, int year, char location);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os)const; //query
        std::istream& read(std::istream& is);
    };
    std::istream& operator>>(std::istream& is, MotorVehicle& mv);
    std::ostream& operator<<(std::ostream& os, MotorVehicle& mv);
}
#endif