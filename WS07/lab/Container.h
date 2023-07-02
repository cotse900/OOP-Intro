#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>

namespace sdds
{
    class Container
    {
        char Content[51];
        int Capacity;
        int Volume;
        bool validContainer;
    protected:
        void setEmpty();
        int capacity();
        int volume();
    public:
        Container(const char* Content, int Capacity, int Volume = 0);
        int operator+=(int value);
        int operator-=(int value);
        bool valid();
        void clear(int Capacity, const char* Content);
        std::ostream& print(std::ostream& ostr);
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, Container& src);
    std::istream& operator>>(std::istream& istr, Container& src);
}

#endif // !SDDS_CONTAINER_H
