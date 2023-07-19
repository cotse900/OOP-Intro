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
Module: Displayable
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#include "Displayable.h"
namespace sdds{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}