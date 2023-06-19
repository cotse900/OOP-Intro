/* ------------------------------------------------------
Workshop 1 part 2
Module: directory
Filename: directory.cpp
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include <iostream>
#include "Phone.h"
using namespace sdds;
int main() {
	phoneDir("Star Wars", "phones.txt");
	std::cout << std::endl << "----------------------------------" << std::endl;
	phoneDir("Broken Phone Book", "badDataFile.txt");
	return 0;
}

