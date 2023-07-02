#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"
namespace sdds
{
	class Pack : public Container
	{
        int unitSize;
        int size;
        int numUnits;
    public:
        Pack(const char* Content, int size, int unitSize = 330, int numUnits = 0);
        int operator+=(int units);
        int operator-=(int units);
        int unit();
        int noOfUnits();
        int Size();
        void clear(int packsize, int unitsize, const char* Content);
        std::ostream& print(std::ostream& ostr);
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, Pack& src);
    std::istream& operator>>(std::istream& istr, Pack& src);
}

#endif // !SDDS_PACK_H