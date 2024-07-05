/*Name: Amany Omar
  Email: aomar22@myseneca.ca 
  ID# 126127166
  Completed on July 1st, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
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
   /*after the while (fin) loop we have m_noOf
   Lines == 0 then we can just set the obj to empty 
   state otherwise else we increment m_noOflines++ as before.*/
    void TextFile::setNoOfLines() {
        char str = '\0';
        m_noOfLines = 0;
        std::ifstream fin(m_filename);
        if (fin.is_open()) {
            while (fin) {
               
                fin.get(str);
                
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
  /*Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
If the m_filename is null, this function does nothing.

If the m_filename is not null (TextFile is not in a safe empty state ),
loadText() will dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.

    Make sure m_textLine is deleted before this to prevent memory leak.

Create a local instance of ifstream using the file name m_filename to read the lines of the text file.

Since the length of each line is unknown, read the line using a local C++ string 
object and the getline helper function. (note: this is the HELPER getline function 
and not a method of istream).

In a loop reads each line into the string object and then sets the m_textLines
array elements to the values returned by the c_str() method of the string object 
until the reading fails (end of file reached).

After all the lines are read, make sure to update the value of m_noOfline to the
actual number of lines read (This covers the possibility of one extra empty line at the end of the file)*/

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
                if (m_textLines[5] != "But my old hound just sat right down and cried") {
                    cout << "<<<Something wrong here>>>" << endl;
                }
                 m_noOfLines = countLines;    

            } fin.close();

            /*m_noOfLines = countLines;*/
        }
    }
 
    void TextFile::saveAs(const char* fileName)const {
        
        std::ofstream fout(fileName);
    
        if (fout.is_open()) {
            unsigned i;
            for (i = 0; i < m_noOfLines - 1; i++) {
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
//operator >>:
  std::istream& operator>>(std::istream& istr, TextFile& text) {
    
    text.getFile(istr);
    return istr;
  }
}
