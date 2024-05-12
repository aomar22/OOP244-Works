#ifndef SENECA_SHOPPINGLIST_H
#define SENECA_SHOPPINGLIST_H


int noOfRecs = 0;
const bool APP_OS_WINDOWS = false;
bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();
#endif 