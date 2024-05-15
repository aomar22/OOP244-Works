#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
using namespace std;
void flushkeys(void);
bool ValidYesResponse(char ch);
bool yes(void);
void readCstr(char cstr[], int len);
int readInt(int min, int max);
#endif
