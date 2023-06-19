/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 27 Jan 2022
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "cStrTools.h"
#define MAX_MODEL 60

namespace sdds
{
	struct Car
	{
		char LicensePlate[8+1];
		char* MakeModel;
		int Time;

	};
	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);	
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();
}
#endif // !SDDS_CAR_H