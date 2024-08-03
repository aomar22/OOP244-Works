#ifndef SENECA_SEARCHNLIST_H
#define SENECA_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"
using namespace std;
namespace seneca {
    
    template<typename T, typename K>
    bool search(Collection<T>& collection, T* m_data, int arraySize, K key)
    {
        bool result = false;
        for (int i = 0; i < arraySize; ++i) {
            if (m_data[i] == key) {
                collection.add(m_data[i]);
                result = true;
            }
        }
        return result;
    }
    /*The search template suppose to search the m_data array looking for matching words(key)
    and if they are found, must be added to the collection. The requirements needed are:
    template declaration: template<typename T, typename K>. Thus it requires type1 T for collection to be added to, and T for m_data and type2 key to find the matches using '=='.
    (m_data[i]==key) also requires an 'operator==' to be able to apply this logic, which is present in the car methods:
      bool Car::operator==(const char* mmSubstr)const;
      Each of the classes Car, Student, Employee have the operator assignment function which enables executing this template.*/

    template<typename T>
    void listArrayElements(const char* m_title, const T* m_data, int arraySize)
    {
        cout << m_title << endl;
        for (int i = 0; i < arraySize; ++i) {
            cout << i+1 << ": " << m_data[i] << endl;
        }
    }
    /*The listArrayElements function is meant to print out a title going through all the array elements.
    For this logic it requires only one type T and extraction operator 'operator<<'.
    For example, ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
    }
    The operator<< overload function works on derived classes which inherit this method from ReadWrite base class.
    For example, all the derived classes: car, Student, and Employee inherit from the base class ReadWrite*/
}
#endif