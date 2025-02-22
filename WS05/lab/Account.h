/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 15, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
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
      Account& operator=(int value);
      Account& operator=(Account& acc);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& acc);
      Account& operator>>(Account& acc);  
   };
   double operator+=(double& sum, const Account& acc);
   double operator+(const Account& a, const Account& b); 
}
#endif // SENECA_ACCOUNT_H_