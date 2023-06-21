/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 5 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
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
			cout << "SPEED             : " << setprecision(2) << std::fixed << trainSpeed << " km/h" << endl;
		}
	}
	bool Train::loadPeople(int num){
		bool success = false;
		if (isSafeEmpty()) {
			success = false;
		}
		else {
			if (numPeople + num >= 0 && numPeople + num <= MAX_PEOPLE) {
				numPeople += num;
				success = true;
			}
			else if (numPeople + num > MAX_PEOPLE) {
				numPeople = MAX_PEOPLE;
				success = true;
			}
			else if (numPeople + num < 0) {
				numPeople = 0;
				success = true;
			}
		}
		return success;
	}
	bool Train::changeSpeed(double speed){
		bool success = false;
		if (isSafeEmpty()) {
			success = false;
		}
		else {
			if (trainSpeed + speed >= 0 && trainSpeed + speed <= MAX_SPEED) {
				trainSpeed += speed;
				success = true;
			}
			else if (trainSpeed + speed > MAX_SPEED) {
				trainSpeed = MAX_SPEED;
				success = true;
			}
			else if (trainSpeed + speed < 0) {
				trainSpeed = 0;
				success = true;
			}
		}
		return success;
	}
	int transfer(Train& train1, Train& train2){
		int num = 0;
		int transferNum = 0;
		if (train1.isSafeEmpty() || train2.isSafeEmpty())
		{
			num = -1;
		}
		else {
			if (train1.getNumberOfPeople() + train2.getNumberOfPeople() <= MAX_PEOPLE) {//e.g. 800,100 or 900,100
				transferNum = train2.getNumberOfPeople();
				train1.loadPeople(transferNum);
				train2.loadPeople(-transferNum);
				num = 1;
			}
			else if (train1.getNumberOfPeople() + train2.getNumberOfPeople() > MAX_PEOPLE) {//e.g. 955,100 in which case 955+45=1000 and 100-45=55
				transferNum = MAX_PEOPLE - train1.getNumberOfPeople();
				train1.loadPeople(transferNum);
				train2.loadPeople(-transferNum);
				num = 1;
			}
		}
		return num;
	}
}