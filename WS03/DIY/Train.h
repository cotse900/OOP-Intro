/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 4 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const int MAX_PEOPLE = 1000;
	const double MAX_SPEED = 320;

	class Train
	{
		char trainName[MAX_NAME_LEN];
		int numPeople;
		double trainSpeed;
		Train* trains;

	public:
		void set(const char* train, int num, double speed);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
		bool loadPeople(int num);
		bool changeSpeed(double speed);
	};
	int transfer(Train& train1, Train& train2);
}
#endif // !SDDS_TRAIN_H