#ifndef SENECA_SHOPPINGREC_H
#define SENECA_SHOPPINGREC_H

class ShoppingRec {
	char m_title[MAX_TITLE_LENGTH + 1];
	int m_quantity;
	bool m_bought;
};
#endif