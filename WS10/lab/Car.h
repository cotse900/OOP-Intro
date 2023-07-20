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
Module: Car
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Displayable.h"
namespace sdds{
  class Car :public Displayable{
     char m_plate[9]{};
     char m_make[41]{};
     char m_model[41]{};
    void set(const char* plate, const char* make, const char* model);
  public:
     Car();
    Car(const char* plate, const char* make, const char* model );
    std::ostream& display(std::ostream& os)const;
    bool operator==(const Car& C)const;
  };
}


#endif
