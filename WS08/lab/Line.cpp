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
#include "Line.h"
using namespace std;

namespace sdds
{
    Line::Line(const char* label, int length) : LblShape(label) {
        if (length > 0) m_length = length;
    }
    void Line::getSpecs(std::istream& istr) {
        int lunghezza;
        bool flag = false;
        do {
            LblShape::getSpecs(istr);
            istr >> lunghezza;
            if (!istr) {
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else {
                istr.ignore();
                m_length = lunghezza;
                flag = true;
            }
        } while (!flag);
    }
    void Line::draw(std::ostream& ostr) const {
        if (m_length > 0 && LblShape::label() != nullptr) {
            ostr << LblShape::label() << endl;
            ostr.width(m_length);
            ostr.fill('=');
            ostr << '=';
        }
    }
}