#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
/*// Holds the number of records (employees) in the file.
// Should be used (after setting) to allocate the dynamic array of Employees.
int noOfEmployees;

// Stores the address of a dynamically-allocated array of employees.
//   The size of the array is "noOfEmployees".
Employee* employees;
*/
using namespace std;
namespace seneca {

   int noOfEmployees = 0;
   Employee* employees = nullptr;


   void sort() {                                                            //sort an array of Employee objects
      int i, j;
      Employee temp;                                                    //will be used to swap elements  during the sorting process
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {                                     //compares adjacent elements and swaps them if necessary.
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employees) {
      bool ok = false;
      char name[128] = "Abraham";
     
      if (read(employees.m_empNo) && read(employees.m_salary) && read(name)) {
          employees.m_name = new char[strlen(name) + 1];
          strcpy(employees.m_name, name);
      }
      // employees.m_empNo = read(employees.m_empNo);
       //employees.m_salary = read(employees.m_salary);
     // if (read(employees.m_empNo) && read(employees.m_salary) && read(name)){
          
                   //remember to deallocate
          
       ok = true;
       delete[] employees.m_name;
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i;
      
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          Employee* employee = nullptr;
          employee = new Employee[noOfEmployees];        //pointer = new type[new size]
         
         
          for (i = 0; i < noOfEmployees; i++) {
            //  load(employees[i]);
              employee[i].m_empNo = employees[i].m_empNo;
              employee[i].m_salary = employees[i].m_salary;
              //Employee* employee.m_name = nullptr;
              employee[i].m_name = new char[strlen(employees[i].m_name) + 1];
              strcpy(employee[i].m_name, employees[i].m_name);           // ( newly allocated ptrEmployees.m_name, original pointer.m_name)

          }
          if (load(employees[i])==0) {
              cout << "Error: inocorrect number of records read;"
                  "the data is possibly corrupted" << endl;
          }
          else {
              ok = true;
          }
         
          closeFile();
         /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocating an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.

          In a loop load the employee records from the file into 
          the dynamic array.

          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if

          close the file
          */
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      
     
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& employees) {
      cout << employees.m_empNo << ":" << employees.m_name << "," << employees.m_salary << endl;
      
   }
   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no - Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; i++) {
               cout << i + 1 << "- ";
               display(employees[i]);
       }

   }

   // TODO: Implementation for the deallocateMemory function goes here
  void deallocateMemory() {
      delete employees;
      for (int i = 0; i < noOfEmployees; i++) {
          delete employees[i].m_name;

      }
      employees = nullptr;
  }


}