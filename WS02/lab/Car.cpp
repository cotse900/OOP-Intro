/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 24 Jan 2022
*/
#include <iostream>
#include "cStrTools.h"
#include "Car.h"
using namespace sdds;
using namespace std;
namespace sdds
{
	Car* carArray;
	int AllocSize;
	int numOfCars;
	int carArraySize;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl;
		cout << "Enter the data in the following format:" << endl;
		cout << "Make and model, LicensePlate, MilitaryTime<ENTER>" << endl;
		cout << "Exit the program by entering the following :" << endl;
		cout << "X, <ENTER>" << endl;
	};
	void initialize(int allocSize) {
		AllocSize = carArraySize = allocSize;
		numOfCars = 0;
		carArray = new Car[allocSize];
	};
	void deallocate(Car& C) {
		delete[] C.MakeModel;
		C.MakeModel = nullptr;
	};
	bool read(Car& C) {
		bool done = false;
		char readMakeModel[MAX_MODEL+1];
		read(readMakeModel, 60, ',');
		if (strCmp(readMakeModel, "X") != 0){
			done = true;
			C.MakeModel = new char[MAX_MODEL+1];
			for (int i = 0; i < MAX_MODEL + 1; ++i) {
				C.MakeModel[i] = readMakeModel[i];
			}
			read(C.LicensePlate, 8+1, ',');
			cin >> C.Time;
		}
		else {
			done = false;
		};
		return done;
	};
	void print(const Car& C) {
		cout << C.Time << ": " << C.MakeModel << "," << C.LicensePlate << endl;
	};
	void record(const Car& C) {
		Car* array_tmp = nullptr;
		if (numOfCars == carArraySize) {
			array_tmp = new Car[carArraySize + AllocSize];
			for (int i = 0; i < carArraySize; ++i) {
				array_tmp[i] = carArray[i];
				
			}
			delete[] carArray;
			carArray = nullptr;
			carArray = array_tmp;
			carArraySize += AllocSize;
		}
		carArray[numOfCars] = C;
		numOfCars++;
	};
	void endOfDay() {
		int i = 0;
		for (i = 0; i < numOfCars; i++) {
			print(carArray[i]);
			deallocate(carArray[i]);
		}
		delete[] carArray;
		carArray = nullptr;
	};

}