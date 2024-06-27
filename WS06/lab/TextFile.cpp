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
        return (const char*)m_value;
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
        delete[] m_value;
    }
    Line::Line() { //default constructor
        //Initializes the m_value attribute to nullptr
        m_value = nullptr;
    }
    void TextFile::setEmpty() {
        //deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring 
        // and sets is to nullptr sets m_noOfLines attribute to zero.
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;

        m_noOfLines = 0;
    }
    //If the isCopy argument is false, dynamically allocates a 
    // Cstring in m_filename and copies the content of the fname argument into it. If the isCopy argument is true, 
    // dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.

 //Example:
   // setFilename("abc.txt"); // sets the m_filename to "abc.txt"
    //setFilename("abc.txt", true); // sets the m_filename to "C_abc.txt"

    void TextFile::setFilename(const char* fname, bool isCopy = false) {
        if (isCopy) {
            fname = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
            m_filename[strlen(fname) + 1] = '\0';
        }
        else {
            fname = new char[strlen(fname) + 1];
                strcpy(m_filename, "C_");
                strncpy(m_filename, fname, strlen(fname)+1);
            
        }
    }
    /*Counts the number of lines in the file:

 Creates a local ifstream object to open the file with the name held in m_filename.
 Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.

 In the end, it will increase m_noOfLines by one,
 just in case, the last line does not have a new line at the end.

 If the number of lines is zero, it will delete
 the m_filename and set it to nullptr. (Setting the TextFile to
 a safe empty state)*/
    void TextFile::setNoOfLines() {
        char str = '\0';
        m_noOfLines = 0;
        std::ifstream localFile(m_filename);
        if (localFile.is_open()) {
            while (localFile) {
                TextFile::lines();const;
                localFile >> str;
                std::cout << str;
                m_noOfLines++;
            }
            if (m_noOfLines == 0) {
                delete[] m_filename;
                m_filename = nullptr;
            }
        }
    }
    /*Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
 If the m_filename is null, this function does nothing.

 If the m_filename is not null (TextFile is not in a safe empty state ), loadText() will 

     Make sure m_textLine is deleted before this to
     prevent memory leak.



 Since the length of each line is unknown, read the line using a
 local C++ string object and the getline helper function. (note:
 this is the HELPER getline function and not a method of istream).

 In a loop reads each line into the string object and then sets
 the m_textLines array elements to the values returned by the
 c_str() method of the string object until the reading fails (end of file reached).

 After all the lines are read, make sure to update the value
 of m_noOfline to the actual number of lines read (This covers
 the possibility of one extra empty line at the end of the file)*/

    void TextFile::loadText() {
        if (m_filename != nullptr) {
            //make sure m_texLine is deleted before this to prevent memory leak
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
                // dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
                m_textLines = new Line[m_noOfLines];
            }

            // Create a local instance of ifstream using the file name m_filename to read the lines of the text file.
            std::ifstream f(m_filename);
            f.open(m_filename);
            int countLines = 0;
            string line;
            if (f.is_open()) { //check if file is open

                while (f && countLines < m_noOfLines) {  //check if it is not the end of the file
                    getline(f, line); //In a loop reads each line into the string object
                    m_textLines[m_noOfLines] = line.c_str();
                    countLines++;
                }

                m_noOfLines = countLines;
            } f.close();
            
        }
    }

    /*Saves the content of the TextFile under a new name.

    Use a local ofstream object to open a new file using the name
    kept in the argument filename. Then loop through the elements of the m_textLines array and write
    them in the opened file adding a new line to the end of each line.*/
    void TextFile::saveAs(const char* fileName)const {
        std::ofstream fin;
        fin.open(m_filename);
        if (fin.is_open()) {
            for (auto i = 0; i < m_noOfLines; i++) {
                fin << m_textLines[i] << endl;
            }
        } fin.close();
    }

    //Constructors:
    TextFile::TextFile(unsigned pageSize = 15) {
        //Creates an empty TextFile and initializes the m_pageSize
        // attribute using the pageSize argument.
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize = 15) {
        m_pageSize = pageSize;
        setEmpty();
        if (filename != nullptr && filename[0] != '\0') {
            filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            m_filename[strlen(filename) + 1] = '\0';
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
    //Copy Constructor:
    /*Initializes the m_pageSize attribute using the m_pageSize of
    the incoming TextFile object and all the other attributes to nullptr and zero. If the incoming Text object is in a valid State,
    performs the following tasks to copy the textfile and the content safely:

        Sets the file-name to the name of the incoming TextFile
        object (isCopy set to true) See setFilename()
        Saves the content of the incoming TextFile under the file
        name of the current TextFile
        set the number of lines
        loads the Text
    */
    //1
    TextFile::TextFile(const TextFile& file) { //copy constructor
        this->m_pageSize = file.m_pageSize;
        setEmpty();
        if (file.m_filename[0] != 0 && file.m_noOfLines != 0) {
            setFilename(file.m_filename, true);
            saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    /*Copy Assignment

    If the current and the incoming TextFiles are valid it will first delete the current text 
    and then overwrites the current file and data by the content of the incoming TextFile.

    deallocate the dynamic array of Text and sets the pointer to null
    Saves the content of the incoming TextFile under the current filename
    Sets the number of lines
    loads the Text*/
    //2
    TextFile& TextFile::operator=(const TextFile& file) {
        if (this->m_noOfLines > 0 && file.m_noOfLines > 0) {
            delete[] m_textLines;
            m_textLines = nullptr;
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
/*Prints the filename and then the content of the file "m_pageSize" lines at a time.

    print the file name
    underline the file name with '=' character
    loops through the lines and print them one by line
    pauses after printing "m_pageSize" lines and prompts the user Hit 
    ENTER to continue... and waits for the user to press enter and repeats until all lines are printed.

The function performs no action if the TextFile is in an empty state.

This function receives and returns an instance of istream and uses the instance for printouts.*/
}

std::istream& TextFile::getFile(std::istream& istr) {
    /*Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text. 
    When done it will return the istr;*/
}
//index operator overload:
const char* TextFile::operator[](unsigned index)const {
    /*Returns the element in the m_textLine array corresponding to the index argument. If the TextFile is in an empty state,
    it will return null. If the index exceeds the size of the array it should loop back to the beginning.

For example, if the number of lines is 10, the
last index should be 9 and index 10 should return the first element
and index 11 should return the second element.*/
}
//Type conversion overloads:
//boolean cast:
TextFile::operator bool()const {
    //Returns true if the TextFile is not in an empty state 
    // and returns false if it is.
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
}
//operator >>:
std::istream& operator>>(std::istream& istr, TextFile& text) {
    /*uses the getFile() method to get the file name from
    console and load the content from the file*/
}

}
