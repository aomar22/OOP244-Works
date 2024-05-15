#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include "ShoppingRec.h"
//using namespace std;
namespace seneca {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif 