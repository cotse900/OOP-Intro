/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 13 Apr 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*------------------------------------------------------
Workshop 10 part 1
Module: Student
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds{

  class Student :public Displayable{
     int m_stno{};
     char m_name[41]{};
     char m_subject[7]{};
     void set(int stno, const char* name, const char* subject  );
  public:
     Student();
     Student(int stno, const char* name, const char* subject );
     std::ostream& display(std::ostream& os)const;
     bool operator==(const Student& S)const;
  };
}
#endif 