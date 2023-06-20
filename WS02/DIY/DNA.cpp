/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "DNA.h"
using namespace std;

namespace sdds
{
    const int dnaChar = 2000;
    DNA* dnaArray = nullptr;
    fstream fs;
    int allocSize = 0;
    int numFound = 0;

    bool beginSearch(const char* filename) {
        fs.open(filename);
        bool flag = false;
        if (fs.is_open()) {
            cout << "DNA search program" << endl;
            numFound = 0;
            allocSize = 0;
            dnaArray = nullptr;
            flag = true;
        }
        return flag;
    };
    bool read(const char* subDNA) {
        bool done = true;
        char dnaString[dnaChar];
        //rewind
        fs.clear();
        fs.seekg(0);
        allocSize = 0;
        while (!fs.eof()) {
            fs.getline(dnaString, dnaChar);
            if (strstr(dnaString, subDNA) != nullptr) {
                allocSize++;
            }
        }
        if (allocSize == 0) {
            done = false;
        }
        dnaArray = new DNA[allocSize];
        //rewind
        fs.clear();
        fs.seekg(0);
        numFound = 0;
        while (!fs.eof()) {
            fs.getline(dnaString, dnaChar);
            if (fs.eof()) break;
            if (strstr(dnaString, subDNA) != nullptr) {
                char* searchID = strtok(dnaString, ",");
                dnaArray[numFound].ID = atoi(searchID);
                char* searchStrand = strtok(NULL, "\n");
                dnaArray[numFound].strand = new char[strlen(searchStrand) + 1];
                strcpy(dnaArray[numFound].strand, searchStrand);
                numFound++;
            }
        }
        return done;
    };
    void sort() {
        DNA temp;
        int i, j = 0;
        for (i = 0; i < numFound - 1; i++) {
            for (j = 0; j < numFound - i - 1; j++) {
                if (dnaArray[j].ID > dnaArray[j + 1].ID) {
                    temp.ID = dnaArray[j].ID;
                    dnaArray[j].ID = dnaArray[j + 1].ID;
                    dnaArray[j + 1].ID = temp.ID;
                    temp.strand = dnaArray[j].strand;
                    dnaArray[j].strand = dnaArray[j + 1].strand;
                    dnaArray[j + 1].strand = temp.strand;
                }
            }
        }
    };
    void displayMatches() {
        cout << numFound << " matches found:" << endl;
        for (int i = 0; i < numFound; i++) {
            cout << i + i << ") " << dnaArray[i].ID << ":" << endl;
            cout << dnaArray[i].strand << endl;
            cout << "======================================================================" << endl;
        }
    };
    void deallocate() {
        for (int i = 0; i < numFound; i++) {
            delete[] dnaArray[i].strand;
            dnaArray[i].strand = nullptr;
        }
        delete[] dnaArray;
        dnaArray = nullptr;
    };
    void endSearch() {
        fs.close();
        cout << "DNA Search Program Closed." << endl << endl;

        deallocate();//edited Sep 2022
    };
}