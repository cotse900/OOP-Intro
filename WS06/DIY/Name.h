/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 6 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
namespace sdds
{
    class Name
    {
        char* firstName;
        char* middleName;
        char* lastName;
        bool shortOnly;
        bool valid;
        bool goodStr(const char* str);
    public:
        void setEmpty();
        void set(const char* fName, const char* mName, const char* lName);
        Name();
        Name(const char* fName);
        Name(const char* fName, const char* lName);
        Name(const char* fName, const char* mName, const char* lName);
        Name(const Name& nem);
        Name& operator=(const Name& nem);
        ~Name();

        bool setShort(bool set);
        Name& operator+=(const char* nem);

        operator bool() const;
        void invalid();
        std::ostream& print(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Name& nem);
    std::istream& operator>>(std::istream& istr, Name& nem);
}
#endif // !SDDS_NAME_H
