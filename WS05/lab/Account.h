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
      Account& operator=(int num);
      Account& operator=(Account& src);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& src);
      Account& operator>>(Account& src);
      friend double& operator+=(double& sum, Account& src);
      friend double operator+(const Account& a, const Account& src);
      
   };
   
   
   
}
#endif // SENECA_ACCOUNT_H_