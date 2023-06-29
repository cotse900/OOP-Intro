/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 6 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Name.h"
using namespace std;
namespace sdds
{
    //to validate each string
    bool Name::goodStr(const char* str) {
        if (str == nullptr) {
            return false;
        }
        int count = 0;
        unsigned j = 0;
        for (; unsigned(j < strlen(str)); j++) {
            if (str[j] == ' ') {
                count++;
            }
        }
        return count == 0 && j > 0;
    };
    //public
    void Name::setEmpty() {
        if (this->firstName != nullptr) {
            delete[] this->firstName;
            this->firstName = nullptr;
        }
        if (this->middleName != nullptr) {
            delete[] this->middleName;
            this->middleName = nullptr;
        }
        if (this->lastName != nullptr) {
            delete[] this->lastName;
            this->lastName = nullptr;
        }
    };
    void Name::set(const char* fName, const char* mName, const char* lName) {
        valid = true;
        if (goodStr(fName)) {
            if (this->firstName != nullptr)
                delete[] this->firstName;

            firstName = new char[strlen(fName) + 1];
            strcpy(firstName, fName);
        }
        if (goodStr(mName)) {
            if (this->middleName != nullptr)
                delete[] this->middleName;

            middleName = new char[strlen(mName) + 1];
            strcpy(middleName, mName);
        }
        if (goodStr(lName)) {
            if (this->lastName != nullptr)
                delete[] this->lastName;
            lastName = new char[strlen(lName) + 1];
            strcpy(lastName, lName);
        }
    };
    Name::Name() {
        firstName = nullptr;
        middleName = nullptr;
        lastName = nullptr;
        shortOnly = false;
        valid = false;
    };
    Name::Name(const char* fName) {
        firstName = nullptr;
        middleName = nullptr;
        lastName = nullptr;
        if (goodStr(fName)) {
            firstName = new char[strlen(fName) + 1];
            strcpy(firstName, fName);
            valid = true;
        }
        else {
            valid = false;
        }
        shortOnly = false;
    };
    Name::Name(const char* fName, const char* lName) {
        firstName = nullptr;
        middleName = nullptr;
        lastName = nullptr;
        if (goodStr(fName) && goodStr(lName)) {
            firstName = new char[strlen(fName) + 1];
            strcpy(firstName, fName);
            lastName = new char[strlen(lName) + 1];
            strcpy(lastName, lName);
            valid = true;
        }
        else {
            valid = false;
        }
        shortOnly = false;
    };
    Name::Name(const char* fName, const char* mName, const char* lName) {
        firstName = nullptr;
        middleName = nullptr;
        lastName = nullptr;
        if (goodStr(fName) && goodStr(mName) && goodStr(lName)) {
            firstName = new char[strlen(fName) + 1];
            strcpy(firstName, fName);
            middleName = new char[strlen(mName) + 1];
            strcpy(middleName, mName);
            lastName = new char[strlen(lName) + 1];
            strcpy(lastName, lName);
            valid = true;
        }
        else {
            valid = false;
        }
        shortOnly = false;
    };
    Name::Name(const Name& nem) {
        firstName = nullptr;
        middleName = nullptr;
        lastName = nullptr;
        set(nem.firstName, nem.middleName, nem.lastName);
        shortOnly = nem.shortOnly;
        valid = nem.valid;
    };
    Name& Name::operator=(const Name& nem) {
        if (this != &nem) {
            set(nem.firstName, nem.middleName, nem.lastName);
            shortOnly = nem.shortOnly;
            valid = nem.valid;
        }
        return *this;
    };
    Name::~Name() {
        setEmpty();
    };
    bool Name::setShort(bool set) {
        shortOnly = set;
        return true;
    };
    Name& Name::operator+=(const char* nem) {//sets each string only when it's nullptr
        if (goodStr(nem)) {
            if (firstName == nullptr) {
                set(nem, nullptr, nullptr);
            }
            else if (middleName == nullptr) {
                set(nullptr, nem, nullptr);
            }
            else if (lastName == nullptr) {
                set(nullptr, nullptr, nem);
            }
            else {
                valid = false;
            }
        }
        return *this;
    };
    //type conversion
    Name::operator bool() const {
        return valid;
    };
    void Name::invalid() {
        valid = false;
    }
    ostream& Name::print(ostream& ostr) const {
        if (!valid) {
            ostr << "Bad Name";
            return ostr;
        }
        if (this->firstName != nullptr) {
            ostr << firstName;
        }
        if (this->middleName != nullptr) {
            if (shortOnly) {
                ostr << " " << middleName[0] << ".";
            }
            else {
                ostr << " " << middleName;
            }
        }
        if (this->lastName != nullptr) {
            ostr << " " << lastName;
        }
        return ostr;
    };
    ostream& operator<<(ostream& ostr, const Name& nem) {
        nem.print(ostr);
        return ostr;
    };
    istream& operator>>(istream& istr, Name& nem) {
        nem.setEmpty();
        string str1 = "", str2 = "", str3 = "";
        char ch;
        int countSpace = 0;
        while (true) {
            ch = istr.get();
            if (ch == ' ') {
                countSpace++;
            }
            else if (ch == '\n' || ch == EOF) {
                break;
            }
            else {
                if (countSpace == 0) {
                    str1 += ch;
                }
                else if (countSpace == 1) {
                    str2 += ch;
                }
                else if (countSpace == 2) {
                    str3 += ch;
                }
                else {
                    break;
                }
            }
        }
        if (countSpace <= 2) {
            if (str1 != "" && str2 != "" && str3 != "") {
                nem.set(str1.c_str(), str2.c_str(), str3.c_str());
            }
            else if (str1 != "" && str2 != "" && str3 == "") {
                nem.set(str1.c_str(), nullptr, str2.c_str());
            }
            else if (str1 != "" && str2 == "" && str3 == "") {
                nem.set(str1.c_str(), nullptr, nullptr);
            }
        }
        else {
            nem.invalid();
        }
        return istr;
    };
}
