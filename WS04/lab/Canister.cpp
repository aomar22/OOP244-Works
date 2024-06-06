 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"
using namespace std;
namespace seneca {
         double const PI = 3.14159265;  //global value
	//private methods
     /*This function sets the attributes to their default values. It sets the content name pointer to null, height to 13.0,
      diameter to 10.0, content volume to 0.0 and usable flag to true.*/
    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }
   /* If the incoming Cstr is not null and the Canister is usable, it will delete the current content name, 
   allocate memory to the length of Cstr(+1 for null) and copies the Cstr into the newly allocated memory.Otherwise,
   it will silently do nothing.*/
        
    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && m_usable) {
            delete[] m_contentName;
            //char* str = nullptr;
            m_contentName = new char[strlen(Cstr) + 1];
            strcpy(m_contentName, Cstr);
        }
    }
    /*Returns true if the content volume is less than 0.00001 CCs*/
    bool Canister::isEmpty()const {
        if (m_contentVolume < 0.00001) {
            return true;
        }
        return false;
    }
    /*Compares the content name of this Canister with the one received 
    from the argument C. Compare the two content names using strcmp from so that it 
    returns true if both names are not null and are identical. Otherwise, it returns false;*/
    bool Canister::hasSameContent(const Canister& C)const {
        if (m_contentName != nullptr && C.m_contentName != "") {
            if (strcmp(m_contentName, C.m_contentName) == 0) {
                return true;
            }
        }
        return false;
    }
    //public methods
    /*Sets the attributes to their default values*/
    Canister::Canister(){      //constructor
        setToDefault();
    }
    /*
    Sets the attributes to their default values (note: reuse code)
    Sets the name to the incoming contentName argument.
*/
    Canister::Canister(const char* contentName) {  //
        setToDefault();
        setName(contentName); //setName
    }
    /*
    Sets the attributes to their default values.

If the dimensions are within acceptable values:

    it will set the m_height and m_diameter to the corresponding argument values
    it will set the content volume to 0.
    it will set the content name to the corresponding argument value.

If any of the dimensions have invalid values, it will set the Canister as unusable*/
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (m_usable) {
            height = m_height;
            diameter = m_diameter;
            Canister(contentName);
        }
    }
    Canister::~Canister() {
        delete[] m_contentName;
    }
    /*It will set the Content name of the canister using the following rule and then returns the reference of the current object (i.e. *this):

If the contentName argument is null it will render the Canister unusable
else if the Canister is empty it will set the name to the value pointed by the argument
else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.*/
    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
                setName(m_contentName);
        }
        else if (!hasSameContent(m_contentName)){
            m_usable = false;
        }
        return *this;
    }
    /*Adds the quantity argument to the content volume of the Canister if the quantity fits in the Canister.
    Otherwise, it will render the Canister unusable and then returns the reference of the current object.
Use this rule to accomplish the above:
If the Canister is usable and the quantity is more than zero and if the sum of the quantity and the volume()
is less than or equal to the capacity(), add the quantity to the content volume, otherwise set usable flag attribute to false.*/
    Canister& Canister::pour(double quantity) {
       // double capacity = Canister::capacity();
        if (m_usable && (quantity > 0)) {
            if (quantity <= Canister::capacity() && volume() <= Canister::capacity()) {
                m_contentVolume += quantity;
            }
        }
        else {
            m_usable = false;
        }
        return *this;
    }
    /*Pours the content of the Canister argument into the current Canister following the Specs stated at the top

Set the content name to the Canister argument using setContent().
if the volume() of the argument is greater than the capacity() minus the volume()
Reduce the content volume of the argument by capacity() minus volume() and then set the content volume to capacity()
else pour the content volume of the argument using pour() method and set the content volume of the argument to 0.0.
return the reference of the current object at the end.*/
    Canister& Canister::pour(Canister&) {
        setContent(m_contentName);
        if (volume() > (capacity() - volume())) {
           m_contentVolume -= (capacity() - volume());
           m_contentVolume = capacity();
        }
        else {
            pour(m_contentVolume);
            m_contentVolume = 0.0;
        }
        return *this;
    }
    //returns the content volume attribute
    double Canister::volume()const {
        return m_contentVolume;
    }
    /*

    Prints all the number values with one digit after the decimal point.

Prints the Canister in the following format:

In 7 spaces prints the capacity
"cc ("
height
"x"
diameter
") Canister"

if unusable:

" of Unusable content, discard!"

otherwise, if the content name is not null

" of "
in 7 spaces prints the volume
"cc   "
content name

returns the cout object at the end.*/
    std::ostream& Canister::display()const {
        cout.width(7);
        cout.precision(1);
        cout << capacity() << "cc (" << Canister::m_height << "x" << Canister::m_diameter << ") Canister";
        if (m_usable) {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << m_contentName << endl;
        }
        else {
            cout << " of Unusable content, discard!" << endl;
        }

        return cout;
    }
    /*returns the capacity as stated in Calculating the capacity*/
    /*PI: 3.14159265  (a global constant double value created in Canister.cpp)
H: Height
D: Diameter
Capacity = PI x (H - 0.267) x (D/2) x (D/2)*/
    double Canister::capacity()const {
        double capacity = 0.0;
       
       capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
        
        return capacity;
    }
    /*Clears an unusable Canister back to an empty Canister by:

    deallocating the memory pointed by the content name attribute
    sets the content name attribute to nullptr
    sets the content volume attribute to 0.0
    set the usable flag attribute to true
*/
    void Canister::clear() {
        Canister::~Canister();
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
   
}