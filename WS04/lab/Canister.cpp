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
            size_t strLen = strlen(Cstr);
            clear();
            m_contentName = new char[strLen + 1];
            strnCpy(m_contentName, Cstr, strLen);
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
        if (m_contentName != nullptr && C.m_contentName) {
            if (strCmp(m_contentName, C.m_contentName) == 0) {
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
            m_height = height;
            m_diameter = diameter;
            setContent(contentName);;
        } 
        m_usable = false;
    }
    Canister::~Canister() {
       delete[] m_contentName;
    }
   
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
   
    Canister& Canister::pour(double quantity) {
        
       // double capacity = Canister::capacity();
        if (m_usable && (quantity > 0)) {
            if (quantity <= capacity() && volume() <= capacity()) {
                m_contentVolume += quantity;
            }
        }
        
        m_usable = false;
        return *this;
    }
   
    Canister& Canister::pour(Canister& C) {
      //  double cVolume = C.volume();
       
        setContent(m_contentName);
        
        if (C.volume() > (C.capacity() - C.volume())) {
           C.m_contentVolume = (capacity() - volume());
           C.m_contentVolume = C.capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }
    //returns the content volume attribute
    double Canister::volume()const {
        return m_contentVolume;
    }
 
    std::ostream& Canister::display()const {
        cout.width(7);
        cout.precision(1);
        cout << Canister::capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!" << endl;
        }
        else {
            cout << " of ";
            cout.width(7);
            cout.precision(1);
            cout << Canister::volume() << "cc   " << m_contentName << endl;
        }

        return cout;
    }
    
    double Canister::capacity()const {
        double capacity = 0.0;
       
       capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
        
        return capacity;
    }
    
    void Canister::clear() {
        Canister::~Canister();
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    //string handling functions
    void strnCpy(char des[], const char src[], size_t len) {
        int i;
        for (i = 0; i < len && src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = 0;
    }
    int strCmp(const char left[], const char right[]) {
        int i;
        for (i = 0; left[i] && right[i]; i++);
        return left[i] - right[i];
    }
   
}

