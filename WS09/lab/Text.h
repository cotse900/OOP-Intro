/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 31 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_

namespace sdds
{
    class Text
    {
        char* m_content;

    protected:
        const char& operator[](int index) const;
    public:
        Text();
        Text(const char* content);
        Text(const Text& txt);
        Text& operator=(const Text& txt);
        virtual ~Text();

        void read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;   
    };
    int getFileLength(std::istream& is);
    std::ostream& operator<<(std::ostream& ostr, const Text& txt);
    std::istream& operator>>(std::istream& istr, Text& txt);
}
#endif // !SDDS_TEXT_H_