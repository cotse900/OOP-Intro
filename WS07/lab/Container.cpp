#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <cstring>
#include "Container.h"
using namespace std;
namespace sdds
{
    void Container::setEmpty() {
        validContainer = false;
        Capacity = 0;
        Volume = 0;
    };
    int Container::capacity() {
        return Capacity;
    };
    int Container::volume() {
        return Volume;
    };
    Container::Container(const char* Content, int Capacity, int Volume) {
        if (Content == NULL || Volume > Capacity) {
            setEmpty();
        }
        else {
            strcpy(this->Content, Content);
            this->Capacity = Capacity;
            this->Volume = Volume;
            validContainer = true;
        }
    };
    int Container::operator+=(int value) {
        if (Volume + value <= Capacity) {
            Volume += value;
        }
        else {
            value = Capacity - Volume;
            Volume = Capacity;
        }
        return value;
    };
    int Container::operator-=(int value) {
        if (Volume - value >= 0) {
            Volume -= value;
        }
        else {
            value = Volume;
            Volume = 0;
        }
        return value;
    };
    bool Container::valid() {
        return validContainer;
    }
    void Container::clear(int Capacity, const char* Content) {
        if (Capacity >= 1 && Content != NULL && Content[0] != '\0') {
            strcpy(this->Content, Content);
            this->Capacity = Capacity;
            this->Volume = 0;
            validContainer = true;
        }
    };
    std::ostream& Container::print(std::ostream& ostr) {
        if (validContainer) {
            ostr << Content << ": (" << Volume << "cc/" << Capacity << ")";
        }
        else {
            ostr << "****: (**cc/***)";
        }
        return ostr;
    };
    std::istream& Container::read(std::istream& istr) {
        if (!validContainer) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
        }
        else {
            int value;
            bool done = false;
            cout << "Add to ";
            print(cout);
            while (!done) {
                cout << endl;
                cout << "> ";
                istr >> value;
                if (value > Capacity) {
                    cout << "Invalid Integer, retry: ";
                }
                else if (value < 1 || value > 999) {
                    cout << "Value out of range [1<=val<=999]: ";
                }
                else {
                    done = true;
                }
            }
            value = (*this += value);
            cout << "Added: " << value << " CCs" << endl;
        }
        return istr;
    };
    std::ostream& operator<<(std::ostream& ostr, Container& src) {
        return src.print(ostr);
    };
    std::istream& operator>>(std::istream& istr, Container& src) {
        return src.read(istr);
    };
}