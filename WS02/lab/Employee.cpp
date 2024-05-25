/*=====================================================================
  - Name: Amany Omar
  - Seneca Email: aomar22@myseneca.ca
  - Std. ID: 126 127 166
  - Date: May 25, 2024
  =====================================================================
  * I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.
  =====================================================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

    int noOfEmployees;
    Employee* employees = nullptr;

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    bool load(Employee& employees) {
        bool ok = false;
        char name[128];

        if (read(employees.m_empNo) == 1 && read(employees.m_salary) == 1 && read(name) == 1) {
            employees.m_name = new char[strlen(name) + 1];
            strcpy(employees.m_name, name);
            ok = true;
        }
        else {
            ok = false;
        }
        return ok;
    }
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees; i++) {
                load(employees[i]);
            }
            if (noOfEmployees != i) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }
    void display(const Employee& employees) {
        cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
    }
    void display() {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
    }

}