#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
  
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
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
   Account::operator bool()const {         //no arguments allowed in type conversion operators
       if (m_number >= 10000 && m_number <= 99999
           && m_balance > 0) {
           return true;
       }
       else {
           return false;
       }
   }
   Account::operator int()const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }
   // Unary operators
   /*bool operator ~()
This operator returns true is the account is new or
not set (i.e. if the account number is zero), otherwise it will return false.
This operator can not modify the account object.*/
   bool Account::operator~() const {
       if (m_number == 0) {
           return true;
       }
       else {
           return false;
       }
   }
   //Binary Members Operators
   //Assingment operators
   /*overload the assignment operator so a NEW account can be set to an integer.
   Doing so should set the account number of the account to the integer value.
If the integer value is an invalid account number, the object should be set
to an invalid empty state instead.
If the account is not new, then this operator should not perform any action.
In any case, a reference of the current object (account) should be returned.*/

/*Account A,B;
A = 55555;  // the account number of A will be set to 55555
B = 555; // the account B will be set to invalid state
B = 66666; // no action will be taken since the B is in not new
A = 66666; // no action will be taken since the A is in not new*/
   Account& Account::operator=(int num) {
       
           if (num >=10000 && num <= 99999) {
               m_number = num;
           }
           else {
               setEmpty();
           }
       
       return *this;
   }
   /*
overload the assignment operator so a NEW account can be set to another Account object.
This action should move the balance and the account number from one account to another;
therefore unlike the usual assignment operator that affects the left operand only,
this operator will affect both operands; the balance of the left account will be set
to the balance of the right account and then the balance of the right account will be set to zero.
The same will happen to the account number
If the left Account operand is not new or the right account operand is not valid, no action should be taken.
In any case, a reference of the current object (account) should be returned.

Account A, B(66666, 400), Bad(555, -10);
A = B;  // A will have the properties of B and B will become a NEW account
B = Bad; // Nothing will happen since Bad is not new
Bad = B; // Nothing will happen since Bad is invalid
*/
   Account& Account::operator=(Account& src) {     //must be modifiable, not constant
       if (src.operator bool()) {

           m_number = src.m_number;
           m_balance = src.m_balance;
           src.m_number = 0;
           src.m_balance = 0.0;
       }
       
       return *this;
   }
   /*
    overload the += operator to add a double value to an account. This should act like depositing money into an account.
    (i.e. the value of the double should be added to the balance)
    if the account is in an invalid state or the double value is negative, no action should be taken.
    In any case, a reference of the current object (account) should be returned.

Account A(55555, 400.0), Bad(555, -10);
   A += 200.0;  // A will have a balance of 600
   Bad += 300.0; // Nothing will happen since Bad is invalid
   A += -20.0; // Nothing will happen since double value is negative
*/
   Account& Account::operator+=(double value) {     //receives double deposit value
       if (operator bool() && value > 0){
           m_balance += value;
       }
       return *this;
   }
   /*
    overload the -= operator to reduce an account balance by a double value . 
    This should act like withdrawing money from an account. (i.e. the value of the balance should be reduced by the double value)
    if the account is in an invalid state, the double value is negative or there is not enough money in the account no action should be taken.
    In any case, a reference of the current object (account) should be returned.

Account A(55555, 400.0), Bad(555, -10);
   A -= 150.0;  // A will have a balance of 250 
   A -= 300.0; // Nothing will happen since there not enough money in A
   A -= -20.0; // Nothing will happen since double value is negative
   Bad -= 20.0 // Nothing will happen since Bad is invalid
*/
   Account& Account::operator-=(double value) {  //receives double value
       if (Account() && value > 0) {
           m_balance -= m_balance;
       }
       else {
           Account();
       }
       return *this;
   }
   /*
    overload the << operator (left shift operator) to move funds from the right account to the left. 
    After this operation, the balance of the left account will be the sum of both and the balance of the right account will be zero.
    Funds of an account should not be able to be moved to itself and this operation does not affect the account.
    In any case, a reference of the current object (account) should be returned.

Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
   A << B;  // A will have a balance of 900.0, B will have a balance of zero
   A << A; // Nothing will happen 
   A << Bad; // Nothing will happen
   Bad << A; // Nothing will happen
*/
   Account& Account::operator<<(Account& src) {
       if (m_number >= 10000 && m_number <= 99999
           && m_balance > 0) {
           m_balance += src.m_balance;
           src.m_balance = 0.0;
       }
       return *this;
   }
    /*
    overload the >> operator (right shift operator) to move funds from the left account to the right.
    After this operation, the balance of the right account will be the sum of both and the balance of the left account will be zero.
    Funds of an account should not be able to be moved to itself and this operation does not affect the account.
    In any case, a reference of the current object (account) should be returned.

Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
   A >> B;  // B will have a balance of 900.0, A will have a balance of zero
   B >> B; // Nothing will happen 
   B >> Bad; // Nothing will happen
   Bad >> B; // Nothing will happen
*/
   Account& Account::operator>>(Account& src) {
       if (m_number >= 10000 && m_number <= 99999
           && m_balance > 0) {
           src.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }
   
       //Binary Helper Operators
       /*-- create a binary stand alone helper + operator that accepts a constant account 
       reference at left and another constant account reference at right and returns a double value.
The double value should be the sum of the balances of the two accounts.
If any of the two accounts is invalid, then zero is returned.

   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum;
   sum = A + B; // sum should be 1000.0
   sum = A + Bad; // sum should be 0 since Bad is invalid
   sum = Bad + B; // sum should be 0 since Bad is invalid
*/
   double operator+(const Account& a, const Account& src){
      // double sum;
       if (a.operator bool() && src.operator bool()) {
           return double(a.m_balance) + double(src.m_balance);
       }
       else {
           return 0.0;
       }
   }
   /*-- create a binary stand alone helper += operator that accepts a 
   double reference at left and a constant account reference at right and returns a double value.
The value of the balance of the right operand (account reference) should be added to the left operand (double reference)
Then the value of the double reference is returned.

   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum = 100, ret;
   ret = sum += A; // sum and ret should be 500.0
*/
   double& operator+=(double& sum, Account& src) {
      
       if (src.operator bool()) {
           sum += src.m_balance;
       }
      return sum;

   }
}