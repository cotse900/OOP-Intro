/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 9 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CarInventory.h"

using namespace std;
namespace sdds
{
	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	};
	CarInventory::CarInventory() {//safe empty state
		resetInfo();
	};
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if (type != nullptr && type[0] != '\0' && brand != nullptr && brand[0] != '\0' && model != nullptr && model[0] != '\0') {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);	
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			*this = CarInventory();
		}
	};
	CarInventory::~CarInventory() {
		deallocate();
	};
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{//validate input or else safe empty state
		deallocate();
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	};
	void CarInventory::printInfo() const {
		cout << "| " << left << setw(11) << m_type << "| " << setw(17) << m_brand << "| " << setw(17) << m_model << "| " << setw(5) << m_year << "| " << setw(4) << right << m_code << " |" << setw(10) << setprecision(2) << fixed << m_price << " |" << endl;
	};
	bool CarInventory::isValid() const {
		bool flag = false;
		if (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_price > 0) {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
	};
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		if (this->m_type != nullptr && this->m_brand != nullptr && this->m_model != nullptr) {
			if (!strcmp(this->m_type,car.m_type) && !strcmp(this->m_brand,car.m_brand) && !strcmp(this->m_model,car.m_model) && this->m_year == m_year) {
				return true;//strcmp
			}
		}
		return false;
	};
	void CarInventory::deallocate() {
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
		delete[] m_model;
		m_model = nullptr;
	};
	bool find_similar(CarInventory car[], const int num_cars) {//strcmp NOT on nullptr
		bool match = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {//strcmp?
					match = true;
				};
			}
		}
		return match;
	};
}