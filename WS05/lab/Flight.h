/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 16 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;
   const double MinimumFuelPer = 600;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      //type conversion operator
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;
      //unary member operator
      bool operator~() const;
      //binary member operators
      Flight& operator=(Flight& rhs);
      Flight& operator=(const int assign);
      Flight& operator=(const double assign);
      Flight& operator+=(const double add);
      Flight& operator+=(const int add);
      Flight& operator-=(const double draw);
      Flight& operator-=(const int draw);
      Flight& operator<<(Flight& move);
      Flight& operator>>(Flight& move);    
   };
   //binary helper operators
   int operator+(const Flight& lhs, const Flight& rhs);
   int operator+=(int& lhs, const Flight& rhs);
}
#endif // SDDS_FLIGHT_H