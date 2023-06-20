/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 2 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const int MAX_PEOPLE = 1000;
	const int MAX_SPEED = 320;

	class Train
	{
		char trainName[MAX_NAME_LEN];
		int numPeople;
		double trainSpeed;
	public:
		void set(const char* train, int num, double speed);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
	};
}
#endif // !SDDS_TRAIN_H