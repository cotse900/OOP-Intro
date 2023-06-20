/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 
*/
#ifndef SDDS_DNA_H
#define SDDS_DNA_H

namespace sdds
{
    struct DNA
    {
        int ID;
        char* strand;
    };

    bool beginSearch(const char* filename);
    bool read(const char* subDNA);
    void sort();
    void displayMatches();
    void deallocate();
    void endSearch();

}
#endif // !SDDS_DNA_H