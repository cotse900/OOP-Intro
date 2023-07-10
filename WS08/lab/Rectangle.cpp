/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 23 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label){
        int compare = strlen(LblShape::label()) + 2;
        if (width > compare && height > 3) {
            m_width = width;
            m_height = height;
        }
    }
    void Rectangle::getSpecs(std::istream& istr){
        int width;
        int height;
        char comma;
        bool flag = false;
        do {
            LblShape::getSpecs(istr);
            istr >> width >> comma >> height;
            if (!istr) {
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else {
                istr.ignore();
                m_width = width;
                m_height = height;
                flag = true;
            }
        } while (!flag);
    }
    void Rectangle::draw(std::ostream& ostr) const{
        if (m_width > 0 && m_height > 0) {
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+' << endl;
            ostr << '|';
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr << left << LblShape::label() << '|' << endl;

            for (unsigned int i = 0; i < (m_height - 3); i++) {
                ostr << '|';
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << ' ' << '|' << endl;
            }
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+';
        }
    }
}