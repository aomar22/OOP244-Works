#ifndef SENECA_SEARCHNLIST_H
#define SENECA_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"
using namespace std;
namespace seneca {
    
    template<typename T, typename K>
    bool search(Collection<T>& collection, T* m_data, int arraySize, K key)
    {
        for (int i = 0; i < arraySize; ++i) {
            if (m_data[i] == key) {
                collection.add(m_data[i]);
                return true;
            }
        }
        return false;
    }

    template<typename T>
    void listArrayElements(const char* m_title, const T* m_data, int arraySize)
    {
        cout << m_title << endl;
        for (int i = 0; i < arraySize; ++i) {
            cout << i+1 << ": " << m_data[i] << endl;
        }
    }
}
#endif