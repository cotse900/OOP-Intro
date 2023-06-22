/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 13 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Robot.h"

using namespace std;
namespace sdds
{
	void Robot::resetInfo() {
		r_name = nullptr;
		r_location = nullptr;
		r_weight = 0;
		r_width = 0;
		r_height = 0;
		r_speed = 0;
		r_deployed = false;
	};
	Robot::Robot() {
		resetInfo();
	};
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed) {
		if (name != nullptr && name[0] != '\0' && location != nullptr && location[0] != '\0') {
			r_name = new char[strlen(name) + 1];
			strcpy(r_name, name);
			r_location = new char[strlen(location) + 1];
			strcpy(r_location, location);
			r_weight = weight;
			r_width = width;
			r_height = height;
			r_speed = speed;
			r_deployed = deployed;
		}
		else {
			*this = Robot();
		}
	};
	Robot::~Robot() {
		deallocate();
	};
	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
	{
		deallocate();
		r_name = new char[strlen(name) + 1];
		strcpy(r_name, name);
		r_location = new char[strlen(location) + 1];
		strcpy(r_location, location);
		r_weight = weight;
		r_width = width;
		r_height = height;
		r_speed = speed;
		r_deployed = deployed;
		return *this;
	};
	void Robot::setLocation(char* location) {
		r_location = location;
	};
	void Robot::setDeployed(bool deployed) {
		cout << (r_deployed ? "YES" : "NO");
	};
	const char* Robot::getName() const {
		return r_name;
	};
	const char* Robot::getLocation() const {
		return r_location;
	};
	bool Robot::isDeployed() const {
		bool flag = false;
		if (r_deployed == true) {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
	};
	bool Robot::isValid() const {
		return (r_speed > 0);
	};
	double Robot::speed() const {
		return r_speed;
	};
	void Robot::display() const {
		string deployed;
		if (r_deployed == true) {
			deployed = "YES";
		}
		else {
			deployed = "NO";
		}
		if (isValid()) {
			cout << "| " << setw(10) << setprecision(1) << fixed << left << r_name << " | " << setw(15) << r_location << " | " << right << setw(6) << r_weight << " | " << setw(6) << r_width << " | " << setw(6) << r_height << " | " << setw(6) << r_speed << " | " << setw(9) << left << deployed << "|" << endl;
		}
	};
	void Robot::deallocate() {
		delete[] r_name;
		r_name = nullptr;
		delete[] r_location;
		r_location = nullptr;
	};
	int conrtolRooomReport(const Robot robot[], int num_robots) {
		int i = 0;
		int invalid = 0;
		int count = 0;
		int fastestFound = 0;
		
		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;

		for (i = 0; i < num_robots && robot[i].isValid(); i++) {
			robot[i].display();
			if (robot[i].isDeployed()) {
			count++;
			}
		}
		if (!robot[i].isValid() && i != num_robots) {
			invalid = i;
		}
		else {

			invalid = -1;
		}
		//extract speed from speed(), compare and save the index of the highest
		if (invalid == -1) {
			cout << "|=============================================================================|" << endl;
			cout << "| SUMMARY:                                                                    |" << endl;
			cout << "| " << setw(3) << count << "robots are deployed.                                                     |" << endl;
			cout << "| The fastest robot is:                                                       |" << endl;
			cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			int index = 0;
			double temp = 0;
			int i = 0;
			for (i = 0; i < num_robots; i++) {			
					if (robot[i+1].speed() > robot[i].speed()) {
						temp = robot[i+1].speed();
						index = i;
					}
					else {
						temp = robot[i].speed();
						index = i-1;
					}
					fastestFound = 1;
			}
			if (fastestFound == 1) {
				robot[index].display();
				cout << "|=============================================================================|" << endl;
			}
			else {
				cout << temp;
			}

		}
		return invalid;
	}
}