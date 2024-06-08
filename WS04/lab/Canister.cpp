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
            size_t strLen = strlen(Cstr);
            m_contentName = new char[strLen + 1];
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
    
    bool Canister::hasSameContent(const Canister& C)const {
        if (m_contentName != nullptr &&
            C.m_contentName != 0 &&
            (strCmp(m_contentName, C.m_contentName) == 0)) {
            return true;
        }
        return false;
    }
    //public methods
    /*Sets the attributes to their default values*/
    Canister::Canister(){      //constructor default
        setToDefault();
    }
    /*
    Sets the attributes to their default values (note: reuse code)
    Sets the name to the incoming contentName argument.
*/
    Canister::Canister(const char* contentName) {  //
        setToDefault();
        setName(contentName);
    }
    
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (m_usable) {
            if (height >= 10.0 && height <=40 &&
                diameter >= 10.0 && diameter <= 30.0) {
               this->m_height = height;
               this->m_diameter = diameter;
                setName(contentName);
            }
        } 
        m_usable = false;
    }
    Canister::~Canister() {
       delete[] m_contentName;
       m_contentName = nullptr;
    }
   
    Canister& Canister::setContent(const char* contentName) {
        if (contentName == " ") {
            
           this->m_usable = false;
        }
        else if (this->isEmpty()) {
                this->setName(contentName);
                m_usable = true;
        }
        else if (!this->hasSameContent(contentName)){
           this->m_usable = false;
        }
        return *this;
    }
   
    Canister& Canister::pour(double quantity) {
        quantity = 0.0;
        double sum = quantity + volume();
       // double capacity = Canister::capacity();
        if (this->m_usable && (quantity > 0)) {
            if (sum <= capacity()) {
                this->m_contentVolume = this->m_contentVolume + quantity;
            }
        }
        else {
           this->m_usable = false;
        }
        return *this;
    }
   
    Canister& Canister::pour(Canister& C) {
      //  double cVolume = C.volume();
       
        this->setContent(C.m_contentName);
        
        if (C.volume() > (capacity() - C.volume())) {
           C.m_contentVolume -= (capacity() - C.volume());
           this->m_contentVolume = capacity();
        }
        else {
            this->pour(C.m_contentVolume);
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
        cout.setf(ios::fixed);
        cout << capacity();
        cout << "cc (";
        cout << m_height;
        cout << "x";
        cout << m_diameter;
        cout << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout.precision(1);
            cout.setf(ios::fixed);
            cout << volume() << "cc   ";
            cout << m_contentName;
             
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
      //  m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    //string handling functions
    void strnCpy(char des[], const char src[], size_t len) {
        size_t i;
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

