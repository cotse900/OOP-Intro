/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 22 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Shape.h"

namespace sdds
{
    std::ostream& operator<<(std::ostream& ostr, const Shape& sp){
        sp.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& sp){
        sp.getSpecs(istr);
        return istr;
    }
}