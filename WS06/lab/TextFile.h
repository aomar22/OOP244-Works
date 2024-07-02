/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 1st, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
#ifndef SENECA_TEXTFILE_H__
#define SENECA_TEXTFILE_H__
#include <iostream>
namespace seneca {
    class TextFile; //forward declaration
   class Line {
      char* m_value{ nullptr }; //holds the address of the dynamically allocated Cstring (to hold a line of the text file)
      operator const char* ()const;
      Line();// {}
      Line& operator=(const char* lineValue);
      ~Line();
      friend class TextFile;
      // copy and copy assignment prevention goes here
      Line(Line&) = delete;
      Line& operator=(const Line&) = delete;

   };

   class TextFile {
       //A pointer to hold the dynamic array of Lines. 
       // This attribute should be initialized to nullptr
       Line* m_textLines{ nullptr };

      //A pointer to hold the dynamic Cstring holding the name of
        //  the file.This attribute should be initialized to nullptr
      char* m_filename{ nullptr };

      //An unsigned integer to be set to 
         //the number of lines in the file.
      unsigned m_noOfLines = 0;

      //The page size is the number of lines that should be displayed 
      // on the screen before the display is paused. After these lines are displayed, the user must hit enter for the next page to appear.
      unsigned m_pageSize = 0;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile& file);
      TextFile& operator=(const TextFile& file);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SENECA_TEXTFILE_H__
