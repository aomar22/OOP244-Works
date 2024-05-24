#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Employee.h"


namespace seneca {
   std::FILE* fptr = nullptr;
    bool openFile(const char filename[]) {
        fptr = std::fopen(filename, "r");
        return fptr != nullptr;
    }
    int noOfRecords() {
        //use this function in the Employee module to determine the size of the dynamic array of employees.
        int noOfRecs = 0;
        char ch;
        while (std::fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) std::fclose(fptr);
    }

    bool read(char* empName) {
        
        if (std::fscanf(fptr, "%[^\n]\n", empName) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool read(int& empNum) {
        
        if (std::fscanf(fptr, "%d,", &empNum) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool read(double& empSalary) {
        
        if (std::fscanf(fptr, "%lf,", &empSalary) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}