/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 31 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include "Text.h"

namespace sdds
{
    class HtmlText : public Text
    {
        char* m_title{ nullptr };
    public:
        HtmlText();
        //HtmlText(const char title[]);
        HtmlText(const char* title);
        HtmlText(const HtmlText& src);
        HtmlText& operator=(const HtmlText& src);
        virtual ~HtmlText();
        std::ostream& write(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const HtmlText& txt);
}
#endif // !SDDS_HTMLTEXT_H_