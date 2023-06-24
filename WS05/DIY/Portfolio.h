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
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;
      void emptyPortfolio();

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       std::ostream& display() const;
       void dispPortfolio() const;
       //operator conversion overloads
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       Portfolio& operator+=(const double add);
       Portfolio& operator-=(const double minus);
       bool operator~() const;
       Portfolio& operator<<(Portfolio& move);
       Portfolio& operator>>(Portfolio& move);
   };
   //binary helper operators
   int operator+(const Portfolio& lhs, const Portfolio& rhs);
   int operator+=(double& lhs, const Portfolio& rhs);
}
#endif // SDDS_Portfolio_H_