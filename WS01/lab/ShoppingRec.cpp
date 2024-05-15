/*A module to hold the shopping record - related functions,
 variables, constants and the ShoppingRec structure.*/
#include <iostream>
#include "ShoppingRec.h"
#include "ShoppingList.h"
#include "Utils.h"

ShoppingRec getShoppingRec() {
    ShoppingRec R = {};
    cout << "Item name: ";
    readCstr(R.m_title, MAX_TITLE_LENGTH);
    cout << "Quantity: ";
    R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
    return R;
}
void displayShoppingRec(const ShoppingRec* shp) {
    cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
        " qty:(" << shp->m_quantity << ")" << endl;
}
void toggleBoughtFlag(ShoppingRec* rec) {
    rec->m_bought = !rec->m_bought;

}
bool isShoppingRecEmpty(const ShoppingRec* shp) {
    return shp->m_title[0] == 0;
}