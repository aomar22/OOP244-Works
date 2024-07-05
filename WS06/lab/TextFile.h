/*Name: Amany Omar
  Email: aomar22@myseneca.ca
  ID# 126127166
  Completed on July 5th, 2024.
  Citation: I have done all the coding by myself and only copied the code that my professor
provided to complete my project milestones.*/
#ifndef SENECA_TEXTFILE_H__
#define SENECA_TEXTFILE_H__
#include <iostream>
namespace seneca {
   class TextFile; 
   class Line {
       char* m_value{nullptr}; 
       operator const char* ()const;
      Line();
      Line& operator=(const char* lineValue);
      ~Line();
      friend class TextFile;
   };
   class TextFile {
      Line* m_textLines{ nullptr };
      char* m_filename{};
      unsigned m_noOfLines;
      unsigned m_pageSize;
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
