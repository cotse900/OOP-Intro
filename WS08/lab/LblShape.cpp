/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 22 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"
using namespace std;

namespace sdds
{
    const char* LblShape::label() const {
        return m_label;
    }
    LblShape::LblShape(const char* label) {
        if (label && label[0] != '\0') {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }
    LblShape::~LblShape() {
        if (m_label) {
            delete[] m_label;
            m_label = nullptr;
        }
    }
    void LblShape::getSpecs(std::istream& istr) {
        string etichetta;
        getline(istr, etichetta, ',');
        delete[] m_label;
        m_label = new char[strlen(etichetta.c_str()) + 1];
        strcpy(m_label, etichetta.c_str());
    }
}