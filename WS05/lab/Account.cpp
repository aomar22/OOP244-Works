/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 15, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {            //invalid state
      m_number = -1;
      m_balance = 0.0;
   }
  
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {        //valid account
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if (~*this) {
          cout << "  NEW  |         0.00 ";
      }
      else {
          cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   //Type Conversion Operator functions
   Account::operator bool()const {         //no arguments allowed in type conversion operators //valid account
       if (m_number >= 10000 && m_number <= 99999
           && m_balance >= 0) {
           return true;
       }
       else {
           return false;
       }
   }
   Account::operator int()const {               //m_number
       return m_number;
   }
   Account::operator double()const{           //m_balance
       return m_balance;
   }
   // Unary operators
   bool Account::operator~() const {
       return m_number == 0;
   }
   //Binary Members Operators
   Account& Account::operator=(int value) {
       if (~*this && value >= 10000 && value <= 99999) {    //
           m_number = value;
       }
       else {
           Account();
       }
      return *this;
   }
    //overload assignment operator
   Account& Account::operator=(Account& acc) {     //must be modifiable, not constant
       if (~*this && acc) {
           m_balance = acc.m_balance;
           acc.m_balance = 0.0;
           m_number = acc.m_number;
           acc.m_number = 0;          
       }     
      return *this;
   }
   
   Account& Account::operator+=(double value) {     //receives double deposit value
       if (*this && value >= 0.0){
           m_balance += value;
       }
       return *this;
   }

   Account& Account::operator-=(double value) {  //receives double value
       if (*this && value >= 0.0 && value < m_balance) { //
           m_balance -= value;
       }
       return *this;
   }
  
   Account& Account::operator<<(Account& acc)
   {
       if (m_number != acc.m_number) {
           m_balance += acc.m_balance;
           acc.m_balance = 0.0;
       }
       return *this; 
   }
   
   Account& Account::operator>>(Account& acc) {
       if (m_number != acc.m_number) {
           acc.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
       
   }
   
     
   double operator+(const Account& a, const Account& b){
      
       if(a.operator bool() && b.operator bool()) {
           return double(a) + double(b);
       }
       return 0.0;
   }
   //binary stand alone helper += operator 
  
   double operator+=(double& sum, const Account& acc) {
      
       if (acc.operator bool()) {
           sum += double(acc);
       }
      return sum;

   }
}