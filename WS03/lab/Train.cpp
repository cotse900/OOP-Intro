/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 2 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;
namespace sdds
{
	void Train::set(const char* train, int num, double speed) {
		if (train != nullptr && strlen(train) > 0 && num >= 0 && num <= MAX_PEOPLE && speed >= 0.0 && speed <= MAX_SPEED) {
			strncpy(trainName, train, MAX_NAME_LEN);
			numPeople = num;
			trainSpeed = speed;
		}
		else {//if data values are invalid, then this sets Train object to a safe empty state with "impossible" values
			trainName[0] = '\0';
			numPeople = -1;
			trainSpeed = -1.0;
		}
	}
	int Train::getNumberOfPeople() const {
		return numPeople;
	}
	const char* Train::getName() const {
		return trainName;
	}
	double Train::getSpeed() const {
		return trainSpeed;
	}
	bool Train::isSafeEmpty() const {
		bool res = false;
		if (trainName[0] == '\0' && numPeople == -1 && trainSpeed == -1.0) {//aligns with the above logic for the safe empty state
			res = true;
		}
		return res;
	}
	void Train::display() const {
		if (isSafeEmpty()) {
			cout << "Safe Empty State!" << endl;
		}
		else {
			cout << "NAME OF THE TRAIN : " << trainName << endl;
			cout << "NUMBER OF PEOPLE  : " << numPeople << endl;
			cout << "SPEED             : " << trainSpeed << " km/h" << endl;
		}
	}
}