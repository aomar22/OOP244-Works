#ifndef SENECA_SEARCHNLIST_H
#define SENECA_SEARCHNLIST_H
#include "Collection.h"
/*Create a function template called search that accepts four arguments in any order you prefer:

    A reference to a Collection of templated objects (template type 1). 
    The Collection is defined in Collection.h
    An array of templated objects; the same type as the Collection type. (template type 1)
    Number of elements in the array of objects
    A key templated value to search for, in the array of objects. (template type 2)

The search function template returns a bool that is true only if at least one match to the key
is found in the array of objects and false otherwise.

The search function goes through all the elements of the array of objects and adds all the matches 
found to the Collection. (use the "==" operator to check for a match between the objects and the key)*/
namespace seneca {
    
    template<typename templateType1, typename templateType2> 
    bool search(Collection<templateType1>& collection, templateType1* objArray, int arraySize, templateType2 key);

    template<typename templateType>
    void listArrayElements(const char* m_title, const templateType* objects, int arrSize);
    /*Lists all the elements of an array.

Create a function template called listArrayElements that accepts three arguments in any order you prefer:

    A const char* for a Title to be printed as the Title of the list.
    A constant array of templated objects (template type)
    The number of the elements of the array.

This function first prints the Title and then goes to newline.

Then it will print the row number and then insert each element of the array into cout with a newline attached.

For example, if this function is called for the following array of integers.

int a[]{10,20,30,40};

using the Title value of "INTEGERS" and the number of elements as 4, the output would be like the following.

INTEGERS
1: 10
2: 20
3: 30
4: 40
*/
    
}
#endif