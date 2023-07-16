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
#include <iostream>
#include <cstring>
#include "HtmlText.h"

namespace sdds
{
    HtmlText::HtmlText()
    {
        m_title = nullptr;
    };
    HtmlText::HtmlText(const char* title) {
    //HtmlText::HtmlText(const char title[]) {
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }
    // The rule of three
    HtmlText::HtmlText(const HtmlText& src): Text(src) {
        m_title = nullptr;
        if (src.m_title != nullptr) {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
    }
    HtmlText& HtmlText::operator=(const HtmlText& src) {
        Text::operator=(src);
        if (src.m_title != nullptr) {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
        return *this;
    }
    HtmlText::~HtmlText() {
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
    }
    std::ostream& HtmlText::write(std::ostream& os) const {
        int i = 0;
        bool ms = false;
        os << "<html><head><title>";
        m_title ? os << m_title : os << "No Title";
        os << "</title></head>\n<body>\n";
        if (m_title) os << "<h1>" << m_title << "</h1>\n";
        while ((*this)[i])
        {
            if ((*this)[i] == ' ')
            {
                if (ms) os << "&nbsp;";
                else {
                    ms = true;
                    os << ' ';
                }
            }
            else if ((*this)[i] == '<')
            {
                os << "&lt;";
                ms = false;
            }
            else if ((*this)[i] == '>')
            {
                os << "&gt;";
                ms = false;
            }
            else if ((*this)[i] == '\n')
            {
                os << "<br />\n";
                ms = false;
            }
            else
            {
                ms = false;
                os << (*this)[i];
            }
            i++;
        }
        os << "</body>\n</html>";

        return os;
    }
    std::ostream& operator<<(std::ostream& ostr, const HtmlText& txt)
    {
        txt.write(ostr);
        return ostr;
    }
}