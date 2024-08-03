#ifndef SENECA_SEARCHNLIST_H
#define SENECA_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"
using namespace std;
namespace seneca {
    
    template<typename templateType1, typename templateType2>
    bool search(Collection<templateType1>& collection, templateType1 objArray[], int arraySize, templateType2 key)
    {
        for (int i = 0; i < arraySize; ++i) {
            if (objArray[i] == key) {
                collection.add(objArray[i]);
                return true;
            }
        }
        return false;
    }

    template<typename templateType>
    void listArrayElements(const char* m_title, const templateType objArray[], int arraySize)
    {
        cout << m_title << endl;
        for (int i = 0; i < arraySize; ++i) {
            cout << i+1 << ": " << objArray[i] << endl;
        }
    }
}
#endif