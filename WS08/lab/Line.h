/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 22 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
        unsigned int m_length{ 0 };
    public:
        Line() {}
        Line(const char* label, int length);
        virtual ~Line() {}

        void getSpecs(std::istream& istr) override;
        void draw(std::ostream& ostr) const override;
    };
}
#endif //!SDDS_LINE_H