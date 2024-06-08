/*Amany Omar, aomar22@myseneca.ca, ID# 126127166, Completed on June 8, 2024.
I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"
using namespace std;
namespace seneca {
         double const PI = 3.14159265;  //global value
	//private methods
    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }
        
    void Canister::setName(const char* Cstr) {
        
        if (Cstr != nullptr && m_usable) { 
            // delete[] m_contentName;
            Canister::~Canister();
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
    
    bool Canister::hasSameContent(const Canister& C)const {
        if (m_contentName != nullptr &&
            C.m_contentName != nullptr &&
            strcmp(m_contentName, C.m_contentName) == 0) {
            return true;
        }
        return false;
    }
    //public methods
    Canister::Canister(){      //constructor default
        setToDefault();
    }
   
    Canister::Canister(const char* contentName) {  
        setToDefault();
        setName(contentName);
    }
    
    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        
        if (height >= 10.0 && height <=40 &&
            diameter >= 10.0 && diameter <= 30.0) {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;   
            setName(contentName);
        } else {
             m_usable = false;
        }
    }
    Canister::~Canister() {
       delete[] m_contentName;
    }
   
    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {       
           m_usable = false;
        }
        else if (isEmpty()) {
           setName(contentName);
        }
        else if (!hasSameContent(contentName)){
           m_usable = false;
        }
        return *this;
    }
   
    Canister& Canister::pour(double quantity) {
        double sum = quantity + volume();
        if (m_usable && (quantity > 0) &&
            sum <= capacity()) {
              m_contentVolume += quantity;
        } else {
            m_usable = false;
        }
        return *this;
    }
   
    Canister& Canister::pour(Canister& C) {  
        setContent(C.m_contentName);
        if (C.volume() > (capacity() - volume())) {
           C.m_contentVolume -= (capacity() - volume());
           m_contentVolume = capacity();
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
        cout.setf(ios::fixed);
        cout << capacity();
        cout << "cc (";
        cout << m_height;
        cout << "x";
        cout << m_diameter;
        cout << ") Canister";
        if (m_usable == false) {
            cout << " of Unusable content, discard!";
        }
        else if (m_usable ==true && m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout.precision(1);
            cout.setf(ios::fixed);            //to display readable numbers
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
      //  Canister::~Canister();
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    //string handling functions
   /* void strnCpy(char des[], const char src[], size_t len) {
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
    }*/
   
}

