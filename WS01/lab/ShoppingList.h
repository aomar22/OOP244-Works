#ifndef SENECA_SHOPPINGLIST_H
#define SENECA_SHOPPINGLIST_H

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