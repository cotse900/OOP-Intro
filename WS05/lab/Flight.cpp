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
Filename: Flight.cpp
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
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }
    //low fuel is when m_fuel < minimum which is 600
    //depart: m_passengers >= 1 and m_fuel >= 600

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    //type conversion operator
    Flight::operator bool() const {
        return (m_passengers > 0 && m_fuel >= MinimumFuelPer * m_passengers);
    };
    Flight::operator int() const {
        return m_passengers;
    };
    Flight::operator double() const {
        return m_fuel;
    };
    Flight::operator const char*() const {
        return m_title;
    };
    //unary member operator
    bool Flight::operator~() const {
        return this->m_passengers == 0;
    };
    //binary member operators
    Flight& Flight::operator=(Flight& rhs) {
        this->m_passengers = rhs.m_passengers;
        this->m_fuel = rhs.m_fuel;
        strcpy(this->m_title,rhs.m_title);
        rhs.m_passengers = 0;
        rhs.m_fuel = 0.00;
        strcpy(rhs.m_title,"EmptyPlane");
        return *this;
    };
    Flight& Flight::operator=(const int assign) {
        if (m_passengers > 0 || m_passengers <= Boen747Capacity) {
            m_passengers = assign;
        }
        return *this;
    };
    Flight& Flight::operator=(const double assign) {
        if (m_fuel > 0.00 && m_fuel < FuelTankCapacity) {
            m_fuel = assign;
        }
        return *this;
    };
    Flight& Flight::operator+=(const double add) {
        if (m_fuel > 0.00 && m_fuel < FuelTankCapacity) {
            m_fuel += add;
        }
        return *this;
    };
    Flight& Flight::operator+=(const int add) {
        if (m_passengers > 0 && m_passengers <= Boen747Capacity) {
            m_passengers += add;
        }
        return *this;
    };
    Flight& Flight::operator-=(const double draw) {//cannot be -ve
        if (m_fuel > 0.00 && m_fuel < FuelTankCapacity) {
            m_fuel -= draw;
        }
        return *this;
    };
    Flight& Flight::operator-=(const int draw) {//max deplane=m_pass
        if (m_passengers > 0 && m_passengers <= Boen747Capacity) {
            m_passengers -= draw;
        }
        return *this;
    };
    //check the addresses of two planes and if they are the same that's the SAME plane **TRUE**
    Flight& Flight::operator<<(Flight& move) {
        if (this && move) {
            do {
                m_passengers++;
                move.m_passengers++;
            } while (m_passengers < Boen747Capacity && move.m_passengers > 0);
        };
        return *this;
    };
    Flight& Flight::operator>>(Flight& move) {
        if (this && move) {
            do {
                m_passengers--;
                move.m_passengers++;
            } while (m_passengers > 0 && move.m_passengers < Boen747Capacity);
        };
        return *this;
    };
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    //binary helper operators
    int operator+(const Flight& lhs, const Flight& rhs) {
        int sum = 0;
        if (lhs && rhs) {
           sum = int(lhs) + int(rhs);
        }
        else {
            sum = 0;
        }
        return sum;
    };
    int operator+=(int& lhs, const Flight& rhs) {
        lhs += int(rhs);
        return lhs;
    };
}