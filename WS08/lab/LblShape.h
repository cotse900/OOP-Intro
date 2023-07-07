/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 22 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        char *m_label {nullptr};
    protected:
        const char *label() const;
    public:
        LblShape() {}
        LblShape(const char* label);
        virtual ~LblShape();
        //deleted actions
        LblShape(const LblShape &src) = delete;
        LblShape &operator=(const LblShape &src) = delete;

        void getSpecs(std::istream &istr) override;
    };

}
#endif //!SDDS_LBLSHAPE_H