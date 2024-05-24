#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Employee.h"

using namespace std;
namespace seneca {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        //use this function in the Employee module to determine the size of the dynamic array of employees.
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* empName) {
        bool result = true;
        if (fscanf(fptr, "%[^\n]\n", empName) == 1) {
            result = true;
        }
        else {
            return false;
        }
        return result;
    }
    bool read(int& empNum) {
        bool result = true;
        if (fscanf(fptr, "%d", empNum) == 1) {
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }
    bool read(double& empSalary) {
        bool result = true;
        if (fscanf(fptr, "%lf,", empSalary) == 1) {
            result = true;
        }
        else {
            result = false;
        }
        return result;

    }
}