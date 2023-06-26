/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 3 Mar 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "HealthCard.h"
using namespace std;
namespace sdds {
    //private methods
    void HealthCard::setEmpty() {
        //delete[] m_name;
        m_name = nullptr;
    };
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
        return (name != nullptr && name[0] != '\0' && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9);
    };
    void HealthCard::allocateAndCopy(const char* name) {
        delete[] m_name;
        m_name = nullptr;
        //m_name = new char[strlen(name) + 1];
        m_name = new char[MaxNameLength];
        strcpy(m_name,name);
    };
    void HealthCard::extractChar(istream& istr, char ch) const {
        if (ch == istr.peek()) {
            istr.ignore(1, ch);
        }
        else {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    };
    ostream& HealthCard::printIDInfo(ostream& ostr) const {
        ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
        return ostr;
    };
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode,vCode);
            strcpy(m_sNumber, sNumber);
        }
        else {
            delete[] m_name;
            setEmpty();
        }
    };
    //constructor
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        set(name, number, vCode, sNumber);
    };
    HealthCard::HealthCard(const HealthCard& hc) {
        if (hc) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        else {
            delete[] m_name;
            m_name = nullptr;
        }
    };
    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this != &hc) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    };
    HealthCard::~HealthCard() {
        delete[] m_name;
        m_name = nullptr;
    };
    HealthCard::operator bool() const {
        bool flag = false;
        if (m_name != nullptr) {
            flag = true;
        }
        return flag;
    };
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
        if (*this) {
            if (toFile) {
                ostr << m_name << ",";
                printIDInfo(ostr) << endl;
            }
            else {
                ostr.setf(ios::left);
                ostr.width(50);
                ostr.fill('.');
                ostr << m_name;
                ostr.unsetf(ios::left);
                printIDInfo(ostr);
            }
        }
        return ostr;
    };
    istream& HealthCard::read(istream& istr) {
        char r_name[MaxNameLength];
        long long r_number;
        char r_vCode[3];
        char r_sNumber[10];
        istr.get(r_name, MaxNameLength,',');
        extractChar(istr, ',');
        istr >> r_number;
        extractChar(istr, '-');
        istr.get(r_vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(r_sNumber, 10, '\n');
        extractChar(istr, '\n');
        if (!istr.fail()) {
            set(r_name,r_number,r_vCode,r_sNumber);
        }
        else{
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    };
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc) {
            hc.print(ostr,false);
        }
        else {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    };
    istream& operator>>(istream& istr, HealthCard& hc) {
        return (hc.read(istr));
    };
}
