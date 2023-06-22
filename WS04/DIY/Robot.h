/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 13 Feb 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
namespace sdds
{
	class Robot
	{
		char* r_name;
		char* r_location;
		double r_weight;
		double r_width;
		double r_height;
		double r_speed;
		bool r_deployed = false;
		void resetInfo();

	public:
		Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		~Robot();
		//modifiers
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
		void setLocation(char* location);
		void setDeployed(bool deployed);
		//queries
		const char* getName() const;
		const char* getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
		void display() const;
		
		void deallocate();
		
	};

	int conrtolRooomReport(const Robot robot[], int num_robots);
}

#endif // !SDDS_ROBOT_H