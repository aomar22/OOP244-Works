#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char* empName);
   bool read(int& empNum);
   bool read(double& empSalary);
 

}
#endif // !SENECA_FILE_H_
