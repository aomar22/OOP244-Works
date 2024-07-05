/*Name: Amany Omar
  Email: aomar22@myseneca.ca 
  ID# 126127166
  Completed on July 4th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones and I needed help from the professor in debugging the code.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace seneca {
    
    Line::operator const char* () const {
        return m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;       
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);

        return *this;
    }
    Line::~Line() {
        
       if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
       }

    }
    Line::Line(){ 
       
        m_value = nullptr;
    }
    void TextFile::setEmpty() {
       
            delete[] m_textLines;
            m_textLines = nullptr;
      
            delete[] m_filename;
            m_filename = nullptr;
         
            m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
            
         if (isCopy) {
               
             m_filename = new char[strlen("C_") + strlen(fname) + 1];
             strcpy(m_filename, "C_");
             strcat(m_filename, fname);

         }
         else {
              m_filename = new char[strlen(fname) + 1];
              strcpy(m_filename, fname);
         }
    }
   
    void TextFile::setNoOfLines() {
        char str = '\0';
        m_noOfLines = 0;
        std::ifstream fin(m_filename);
        if (fin.is_open()) {
            while (fin.get(str)) {
               
                /*fin.get(str);*/
                
                if (str == '\n') {
                    m_noOfLines++;
                }
            }
            if (m_noOfLines == 0) {

                setEmpty();
            }
             else {
                  m_noOfLines++;
             }
        } 
    }

    void TextFile::loadText() {
        if (*this) { // bool() -> boolean = false
          
            delete[] m_textLines;
            m_textLines = nullptr;

            m_textLines = new Line[m_noOfLines];

            std::ifstream fin;
            fin.open(m_filename);
            unsigned countLines = 0;
            string line;

            if (fin) { 
              
                while (getline(fin, line)) {  //In a loop reads each line into the string object

                    m_textLines[countLines].m_value = new char[line.length() + 1];
                    
                    m_textLines[countLines] = line.c_str();  
                    
                    countLines++;    
                }  
                
                 m_noOfLines = countLines;  
            } fin.close();
        }
    }
 
    void TextFile::saveAs(const char* fileName)const {
        
        std::ofstream fout(fileName);
    
        if (fout.is_open()) {
            unsigned i;
            for (i = 0; i < m_noOfLines; i++) {
                fout << m_textLines[i] << '\n';
            }
        } fout.close();
    }

    //Constructors:
    TextFile::TextFile(unsigned pageSize) {
        
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
       
        setEmpty();
        m_pageSize = pageSize;
        
        if (filename != nullptr) {
            
            setFilename(filename);
            setNoOfLines();
            loadText();

        }
    }
    //Rule of three implementations for classes with resource:

    TextFile::TextFile(const TextFile& file) { //1 copy constructor
        
        setEmpty();
        this->m_pageSize = file.m_pageSize;
        if (this != &file) {
            if (file.m_textLines && file.m_noOfLines > 0) {

                setFilename(file.m_filename, true);
                file.saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
    }

    //2 Copy Assignment
    TextFile& TextFile::operator=(const TextFile& file) {
       
        if(this != &file){
           delete[] m_textLines;
           m_textLines = nullptr;
           file.saveAs(m_filename);
           setNoOfLines();
           loadText();
        }
        return *this;
    }
  
    TextFile::~TextFile() { // 3 destructor
      
         delete[] m_textLines;
         m_textLines = nullptr;
         delete[] m_filename;
         m_filename = nullptr;
    }

    //Public Methods:
unsigned TextFile::lines()const{
    return m_noOfLines;
}

std::ostream& TextFile::view(std::ostream& ostr)const {
   
    if (m_filename != nullptr) {

        ostr << this->m_filename << endl;
        unsigned long i = 0;
        unsigned long j = 0;
        for (i = 0; i < strlen(m_filename); i++) {
            ostr << '=';
        }
        ostr << endl;
        for (i = 0; i < m_noOfLines && j < m_pageSize; i++) {
            ostr << m_textLines[i] << endl;
            j++;
            if (j == m_pageSize) {
                ostr << "Hit ENTER to continue...";
                cin.ignore();
                j = 0;
            }
        }
    }
    return ostr;
}
 
std::istream& TextFile::getFile(std::istream& istr) {
    string s;
    getline(istr, s);
    m_filename = new char[s.length() + 1];
    strcpy(m_filename, s.c_str());
    setFilename(m_filename);
    istr.ignore(10000, '\n');
    setNoOfLines();
    loadText();
    return istr;
}
    

//index operator overload:
const char* TextFile::operator[](unsigned index)const {
    if (m_filename != nullptr && m_filename[0] != '\0') {

        unsigned temp = index % m_noOfLines;
        return m_textLines[index % m_noOfLines].m_value;  
    }
    else {
        return nullptr;
    }
    
}

//Type conversion overloads:
//boolean cast:
TextFile::operator bool()const {
   
    if (m_filename) {
        return true;
    }
    else {
        return false;
    } 
}

const char* TextFile::name()const {
   
    return m_filename;
}

std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
 
    text.view(ostr);
    return ostr;
}
  std::istream& operator>>(std::istream& istr, TextFile& text) {
    
    text.getFile(istr);
    return istr;
  }
}
