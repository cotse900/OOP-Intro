/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 22 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        virtual void draw(std::ostream& ostr) const = 0;
        virtual void getSpecs(std::istream& istr) = 0;
        virtual ~Shape() {}
    };
    std::ostream& operator<<(std::ostream& ostr, const Shape& sp);
    std::istream& operator>>(std::istream& istr, Shape& sp);
}

#endif //!SDDS_SHAPE_H