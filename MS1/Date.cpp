// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;
#include "Date.h"
#include "Utils.h"
namespace seneca {
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }

   /*
- Reads the year, the month and the day member variables using istream and ignores a single character
after the year and the month values to bypass the Slashes.
> Note that the separators do not have to be Slash characters **“/”** but any separator that is not an integer number.
- Checks if istream has failed. If it did fail, it will set the error code to CIN_FAILED and clears the istream. If not, it will validate the values entered.
- Flushes the keyboard
- Returns the istream object*/
   std::istream& Date::read(std::istream& is)
   {
       int integerVariable = 0; //to check if the input not a number
       errCode(NO_ERROR);  //Clears the error code by setting it NO_ERROR
       is >> m_year;
       is >> m_mon;
       is >> m_day;
       if (!cin >> integerVariable) {
           is.ignore(1);
           
       }
       if (is.bad()) {
           errCode(CIN_FAILED);
           is.clear();
          
       }
       else {
           // dateStatus();
           validate();
       }
       
       
       

      return is;
   }

   /*If the Date object is in a “bad” state (it is invalid) print the “dateStatus()”.
Otherwise, the function should write the date in the following format using the ostream object:
- Prints the year
- Prints a Slash “/”
- Prints the month in two spaces, padding the left digit with zero if the month is a single-digit number
- Prints a Slash “/”
- Prints the day in two spaces, padding the left digit with zero if the day is a single-digit number
- Makes sure the padding is set back to spaces from zero
- Returns the ostream object.*/

   std::ostream& Date::write(std::ostream& os) const
   {
       if (bad()) {
           cout << dateStatus();
       }
       else {
           os << m_year << "/";
           os.width(2);  
           os.fill('0');         //padding the left digit with zero if the day is a single - digit number
           os << m_mon << "/";
           os.width(2);
           os.fill('0');   
           os << m_day;
           os.fill(' ');     //setting back to space
       }
       return os;
   }   
   bool Date::operator==(const Date& RO)const {
       return this->daysSince0001_1_1() == RO.daysSince0001_1_1();
   }
   bool Date::operator!=(const Date& RO)const {
       return this->daysSince0001_1_1() != RO.daysSince0001_1_1();
   }
   bool Date::operator>=(const Date& RO)const {
       return this->daysSince0001_1_1() >= RO.daysSince0001_1_1();
   }
   bool Date::operator<=(const Date& RO)const {
       return this->daysSince0001_1_1() <= RO.daysSince0001_1_1();
   }
   bool Date::operator<(const Date& RO)const {
       return this->daysSince0001_1_1() < RO.daysSince0001_1_1();
   }
   bool Date::operator>(const Date& RO)const {
       return this->daysSince0001_1_1() > RO.daysSince0001_1_1();
   }

   int Date::operator-(const Date& RO)const {

       return this->m_day - RO.m_day;
   }

   Date::operator bool() {
       //It will return true if the date is valid and false if it is not.
       if (validate()) {
           return true;
       }
       return false;
   }

   
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const { //returns true if the Date is in an erroneous state.
       if (errCode() == -1);
           return m_ErrorCode != 0; 
       }
      
   std::ostream& operator<<(std::ostream& os, const Date& RO)
   {
       return RO.write(os);
   }

   std::istream& operator>>(std::istream& is, Date& RO)
   {
       return RO.read(is);
   }

}

  
   /*ostream& operator<<(ostream& os, const Date& RO) {
      
   }*/
   /*istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }*/

   //return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;

