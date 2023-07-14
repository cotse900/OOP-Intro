/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 31 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace sdds
{
    int getFileLength(std::istream& is) {
        int len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // let what is the positions (end position = size)
            len = is.tellg();
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }
    Text::Text() {
        m_content = new char[1];
        m_content[0] = '\0';
    }
    Text::Text(const char* content) {
        if (content != nullptr) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            m_content = new char[1];
            m_content[0] = '\0';
        }
    }
    Text::Text(const Text& txt) {
        m_content = new char[strlen(txt.m_content) + 1];
        strcpy(m_content, txt.m_content);
    }
    const char& Text::operator[](int index) const {
        return m_content[index];
    }
    Text& Text::operator=(const Text& txt) {
        delete[] m_content;
        m_content = nullptr;
        m_content = new char[strlen(txt.m_content) + 1];
        strcpy(m_content, txt.m_content);
        return *this;
    }
    Text::~Text() {
        if (m_content) {
            delete[] m_content;
            m_content = nullptr;
        }
    }
    void Text::read(std::istream& istr) {
        delete[] m_content;
        m_content = nullptr;
        int size = getFileLength(istr) + 1;
        m_content = new char[size];
        istr.getline(m_content, size, -1);
    }
    std::ostream& Text::write(std::ostream& ostr) const {
        if (m_content) {
            ostr << m_content;
        }
        return ostr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Text& txt) {
        txt.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Text& txt) {
        txt.read(istr);
        return istr;
    };
}