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
    //Returns the address held in the m_value attribute.
    Line::operator const char* () const {
        return m_value;
    }
    //Dynamically allocates memory in 
    // m_value and copies the Cstring pointed by lineContent into it.
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;       
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);

        return *this;
    }
    Line::~Line() {
        //Makes sure all the allocated memory is freed.
        //Make sure Line can not be copied or assigned 
        // to another Line.
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }

    }
    Line::Line() { //default constructor
        //Initializes the m_value attribute to nullptr
        m_value = nullptr;
    }
    void TextFile::setEmpty() {
        //deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring 
        // and sets is to nullptr sets m_noOfLines attribute to zero.
        
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
            
            m_noOfLines = 0;
    }
    //If the isCopy argument is false, dynamically allocates a 
    // Cstring in m_filename and copies the content of the
    // fname argument into it. If the isCopy argument is true, 
    // dynamically allocates a Cstring in m_filename and
    // copies the content of the fname argument with 
    // a prefix of "C_" attached to it.

 //Example:
   // setFilename("abc.txt"); // sets the m_filename to "abc.txt"
    //setFilename("abc.txt", true); // sets the m_filename to "C_abc.txt"

    void TextFile::setFilename(const char* fname, bool isCopy) {
       // if (fname[0] != 0 && m_filename[0] != 0) {
            if (isCopy) {

                m_filename = new char[strlen("C_") + strlen(fname) + 1];
                strcpy(m_filename, "C_");
                strcat(m_filename, fname);

            }
            else {
                m_filename = new char[strlen(fname) + 1];
                strcpy(m_filename, fname);
               // m_filename[strlen(fname) + 1] = '\0';

            }
     
    }
   
    void TextFile::setNoOfLines() {
        char str = '\0';
        m_noOfLines = 0;
        std::ifstream fin(m_filename);
        if (fin.is_open() && m_noOfLines != 0) {
            while (fin) {
                //  TextFile::lines();const;
                fin.get(str);
                //std::cout << str;
                if (str == '\n') {
                    m_noOfLines++;
                }
            }
            m_noOfLines++;
        } else {
               /* delete[] m_filename;
                m_filename = nullptr;*/
            setEmpty();
        }
        
    }
  
    void TextFile::loadText() {
        if (bool()) {
             //make sure m_texLine is deleted before this to prevent memory leak
                             
              delete[] m_textLines;
              m_textLines = nullptr;
            // dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
                
              m_textLines = new Line[m_noOfLines];
            
                
                              // Create a local instance of ifstream using the
                              // file name m_filename to read the lines of the
                              // text file.
               std::ifstream fin;
               fin.open(m_filename);
               unsigned countLines = 0;
               string line;
               if (fin) { //check if file is open
                   while (fin) {  //check if it is not the end of the file
                       getline(fin, line); //In a loop reads each line into the string object
                      // m_textLines[countLines].m_value = new char[strlen(line.c_str()) + 1];
                       m_textLines[countLines].m_value = new char[line.length()+1];
                       m_textLines[countLines] = line.c_str();
                      // strcpy(m_textLines[countLines].m_value, line.c_str());
                       // m_textLines[countLines].m_value = '\0';
                       countLines++;
                   }                
                   
               } 
               
            
             m_noOfLines = countLines;
             
            
        }
        
    }

         
    
 
    void TextFile::saveAs(const char* fileName)const {
        
        std::ofstream fin(fileName);
        fin.open(fileName);
        if (fin.is_open()) {
            unsigned i;
            for (i = 0; i < m_noOfLines; i++) {
                fin << m_textLines[i];
                fin << '\n';
            }
        } 
    }

    //Constructors:
    TextFile::TextFile(unsigned pageSize) {
        //Creates an empty TextFile and initializes the m_pageSize
        // attribute using the pageSize argument.
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
       
        setEmpty();
        m_pageSize = pageSize;
        
        if (filename != nullptr) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
           // m_filename[strlen(filename) + 1] = '\0';
            setFilename(m_filename);
            setNoOfLines();
            loadText();

        }
        /*Initializes the m_pageSize attribute using the pageSize argument
        and all the other attributes to nullptr and zero. Then if the filename
        is not null, it will set the filename, set the number of
        Lines and load the Text (using the corresponding private methods.)*/
    }
    //Rule of three implementations for classes with resource:
        //Implement The Copy Constructor, Copy assignment and destructor.
 
    //1
    TextFile::TextFile(const TextFile& file) { //copy constructor
        
        setEmpty();
        this->m_pageSize = file.m_pageSize;
        if (this != &file) {
            if (file.m_textLines && file.m_noOfLines > 0) {

                setFilename(file.m_filename, true);
                this->m_noOfLines = file.m_noOfLines;
                delete[] m_textLines;
                m_textLines = nullptr;
                m_textLines = new Line[m_noOfLines];
                unsigned i = 0;
                while (i < m_noOfLines) {

                    m_textLines[i].m_value = new char[strlen(file.m_textLines[i].m_value) + 1];
                    strcpy(m_textLines[i].m_value, file.m_textLines[i]);
                    i++;
                }

                saveAs(m_filename);
            }
            setNoOfLines();
            loadText();
        }
    }

    //Copy Assignment

    TextFile& TextFile::operator=(const TextFile& file) {
       // if (this->m_noOfLines > 0 && file.m_noOfLines > 0) {
        if(this != &file){
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }
            m_textLines = new Line[m_noOfLines];
            unsigned i = 0;
            while (i < m_noOfLines) {

                m_textLines[i].m_value = new char[strlen(file.m_textLines[i].m_value) + 1];
                strcpy(m_textLines[i].m_value, file.m_textLines[i]);
                i++;
            }
            saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }
    /*destructor

    Deletes all the dynamic data.
    */
    //3
    TextFile::~TextFile() {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    //Public Methods:
unsigned TextFile::lines()const{
    return m_noOfLines;
}

std::ostream& TextFile::view(std::ostream& ostr)const {
    // if (m_filename != nullptr && m_filename[0] != '\0') {
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
       /* ostr.fill('=');
        ostr.width(strlen(m_filename));
        ostr << '=' << endl;
        
        while (i < m_noOfLines && i < m_pageSize) {
            ostr << m_textLines[i] << endl;
            i++;
        }
        if (i < m_noOfLines) {
            while (i < m_noOfLines) {
                ostr << "Hit Enter to Continue...";
                char c;
                cin.get(c);
                for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++) {
                    ostr << m_textLines[i] << endl;
                    i++;
                }
            }
        }
    }
    return ostr;
}*/
/*Prints the filename and then the content of the file "m_pageSize" lines at a time.

    print the file name
    underline the file name with '=' character
    loops through the lines and print them one by line
    pauses after printing "m_pageSize" lines and prompts the user Hit 
    ENTER to continue... and waits for the user to press enter and repeats until all lines are printed.

The function performs no action if the TextFile is in an empty state.

This function receives and returns an instance of istream and uses the instance for printouts.*/


std::istream& TextFile::getFile(std::istream& istr) {
    string s;
    getline(istr, s);
    m_filename = new char[s.length() + 1];
    strcpy(m_filename, s.c_str());
   
    
  //  m_filename[] = s.c_str();
    //strcpy(m_filename, s.c_str());
    setFilename(m_filename);
    istr.ignore(10000, '\n');
    setNoOfLines();
    loadText();
    return istr;
}
    /*Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text. 
    When done it will return the istr;*/

//index operator overload:
const char* TextFile::operator[](unsigned index)const {
    if (m_filename != nullptr && m_filename[0] != '\0') {
        if (index >= m_noOfLines) {
            index -= m_noOfLines; //loop back to the beginning e.g. index = noOfLines = 10, index = 10 - 10, index = 0 (loop back)
        //or index%= m_noOfLines;
        }
        else {
            return nullptr;
        }
    }
    return m_textLines[index].m_value;
}
    /*Returns the element in the m_textLine array corresponding to the index argument. If the TextFile is in an empty state,
    it will return null. If the index exceeds the size of the array it should loop back to the beginning.

For example, if the number of lines is 10, the
last index should be 9 and index 10 should return the first element
and index 11 should return the second element.*/

//Type conversion overloads:
//boolean cast:
TextFile::operator bool()const {
    //Returns true if the TextFile is not in an empty state 
    // and returns false if it is.
    if (m_filename != nullptr && m_textLines != nullptr && m_noOfLines > 0) {
        return true;
    }
    else {
        return false;
    }
     
  
    
}

//constant character pointer cast:
const char* TextFile::name()const {
    //returns the filename.
    return m_filename;
}
//Insertion and extraction helper operator overload:
//To print and read on and from istream and ostream overload operator<< and operator>>:
std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
    //operator <<
    //uses the view() method to print the TextFile
    text.view(ostr);
    return ostr;
}
//operator >>:
  std::istream& operator>>(std::istream& istr, TextFile& text) {
    /*uses the getFile() method to get the file name from
    console and load the content from the file*/
    text.getFile(istr);
    return istr;
  }

}
