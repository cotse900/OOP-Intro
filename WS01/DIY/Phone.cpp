/*
	OOP244
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NDD
	Date   : 24 Jan 2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"
using namespace std;

const int MAX_ITEMS = (36);
namespace sdds
{
	struct PhoneEntry
	{
		char name[51];
		char area[4];
		char prefix[4];
		char number[5];
	};

	void phoneDir(const char* programTitle, const char* fileName){
		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
		FILE* fptr = fopen(fileName, "r");
		if (fptr != NULL) {
			char name[51] = "";
			char input[51];
			char lower[51];
			char partial[51];
			char area[4];
			char prefix[4];
			char number[5];
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin >> input;
			while (input[0] != '!') {
				while (!feof(fptr)) {
					toLowerCaseAndCopy(lower,input);
					fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", name, area, prefix, number);
					toLowerCaseAndCopy(partial, name);
					if ((strStr(partial,lower)) != NULL) {
						cout << name << ": (" << area << ") " << prefix << "-" << number << endl;
					}
				}
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> input;
				rewind(fptr);
			}
			if (input[0] == '!')
				cout << "Thank you for using " << programTitle << " directory." << endl;
				fclose(fptr);
				fptr = NULL;
		}
		else {
			cout << fileName << " file not found!" << endl;
			cout << "Thank you for using " << programTitle << " directory." << endl;
		}
	}

}
