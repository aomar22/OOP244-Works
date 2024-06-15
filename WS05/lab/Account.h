#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;
      //bool valid()const;
      Account& operator=(int value);
      Account& operator=(Account& acc);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& acc);
      Account& operator>>(Account& acc);
      friend double operator+=(double& sum, const Account& acc);
      friend double operator+(const Account& a, const Account& b);
      
   };
   
   
   
}
#endif // SENECA_ACCOUNT_H_