/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 24 Jan 2022
*/
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#include <cstdio>
namespace sdds
{
    struct PhoneEntry
    {
        char name[51];
        char area[4];
        char prefix[4];
        char number[5];
    };

	void phoneDir(const char* programTitle, const char* fileName);

    extern std::FILE* fptr;
}
#endif // !SDDS_PHONE_H
