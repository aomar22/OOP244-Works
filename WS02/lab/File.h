#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char m_name[]);
	bool read(int& m_empNo);
	bool read(double& m_salary);
}
#endif // !SENECA_FILE_H_
