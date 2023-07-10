/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 23 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };
    public:
        Rectangle() {}
        Rectangle(const char* label, int width, int height);
        virtual ~Rectangle() {}

        void getSpecs(std::istream& istr) override;
        void draw(std::ostream& ostr) const override;
    };
}
#endif //!SDDS_RECTANGLE_H