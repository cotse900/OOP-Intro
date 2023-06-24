/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 18 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    //operator conversion overloads
    Portfolio::operator double() const {
        return m_value;//
    };
    Portfolio::operator const char* () const {
        return m_stock;//
    };
    Portfolio::operator char() const {
        return m_type;//
    };
    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');//
    };
    Portfolio& Portfolio::operator+=(const double add) {
        if (this && m_value > 0) {
            m_value += add;
        }
        return *this;//
    };
    Portfolio& Portfolio::operator-=(const double minus) {
        if (this && m_value > 0) {
            m_value -= minus;
        }
        return *this;//
    };
    bool Portfolio::operator~() const {
        return (m_value < 0);
    };
    Portfolio& Portfolio::operator<<(Portfolio& move) {
        if (this && move) {
            m_value += move.m_value;
            move.emptyPortfolio();
        };
        return *this;
    };
    Portfolio& Portfolio::operator>>(Portfolio& move) {
        if (this && move) {
            move.m_value += m_value;
            emptyPortfolio();
        };
        return *this;
    };

    //binary helper operators
    int operator+(const Portfolio& lhs, const Portfolio& rhs) {
        double sum = 0.00;
        if (lhs && rhs) {
            sum = double(lhs) + double(rhs);
        }
        else {
            sum = 0;
        }
        return sum;
    };
    int operator+=(double& lhs, const Portfolio& rhs) {
        lhs += double(rhs);
        return lhs;
    };
}