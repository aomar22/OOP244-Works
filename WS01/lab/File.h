/*Amany Omar, aomar22@myseneca.ca, 126 127 166, completed on May 14th.
I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.*/
#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include "ShoppingRec.h"
namespace seneca {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif 