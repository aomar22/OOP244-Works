/*=====================================================================
  - Name: Amany Omar
  - Seneca Email: aomar22@myseneca.ca
  - Std. ID: 126 127 166
  - Date: May 25, 2024
  =====================================================================
  * I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.
  =====================================================================*/
#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char* m_name);
	bool read(int& m_empNo);
	bool read(double& m_salary);
}
#endif // !SENECA_FILE_H_
