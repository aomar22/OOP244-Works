#ifndef SENECA_SEARCHNLIST_H
#define SENECA_SEARCHNLIST_H
#include "Collection.h"

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
        std::cout << m_title << std::endl;
        for (int i = 0; i < arraySize; ++i) {
            std::cout << i+1 << ":" << objArray[i] << std::endl;
        }
    }
}
#endif