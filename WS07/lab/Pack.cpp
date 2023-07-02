#include <iostream>
#include "Pack.h"

namespace sdds
{
    Pack::Pack(const char* Content, int size, int unitSize, int numUnits)//2/3/4 args
        : Container(Content, size * unitSize, numUnits * unitSize) {//content, capacity = size * unit size, volume = numUnits * unit size
        if (unitSize > 0) {
            this->unitSize = unitSize;
            this->size = size;
            this->numUnits = numUnits;
        }
        else {
            Container::setEmpty();
        }
    };
    int Pack::operator+=(int units) {
        int packs = Container::operator+=(units * unitSize) / unitSize;
        this->numUnits += packs;
        return packs;
    };
    int Pack::operator-=(int units) {
        int packs = Container::operator-=(units * unitSize) / unitSize;
        this->numUnits -= packs;
        return packs;
    };
    int Pack::unit() {
        return unitSize;
    };
    int Pack::noOfUnits() {
        return numUnits;
    };
    int Pack::Size() {
        return size;
    };
    void Pack::clear(int packSize, int unitSize, const char* Content) {
        if (unitSize > 0) {
            Container::clear(packSize * unitSize, Content);
            this->size = packSize;
            this->unitSize = unitSize;
            this->numUnits = 0;
        }
    };
    std::ostream& Pack::print(std::ostream& ostr) {
        Container::print(ostr);
        if (valid()) {
            ostr << ", " << numUnits << " in a pack of " << size;
        }
        return ostr;
    };
    std::istream& Pack::read(std::istream& istr) {
        int localunits = 0;
        if (!valid()) {
            std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
        }
        else if (numUnits != size) {
            bool done = false;
            std::cout << "Add to ";
            print(std::cout);
            int missing = size - numUnits;
            while (!done) {
                std::cout << std::endl;
                std::cout << "> ";
                istr >> localunits;
                if (localunits > size) {
                    std::cout << "Invalid Integer, retry: ";
                }
                else if (localunits < 1 || localunits > missing) {
                    std::cout << "Value out of range [1<=val<=" << missing << "]: " << missing << std::endl;
                    done = true;
                }
                else {
                    done = true;
                }
            }
            localunits = (*this += localunits);
            std::cout << "Added: " << localunits << std::endl;
        }
        else {
            std::cout << "Pack is full!, press <ENTER> to continue..." << std::endl;
        }
        return istr;
    };
    std::ostream& operator<<(std::ostream& ostr, Pack& src) {
        return src.print(ostr);
    };
    std::istream& operator>>(std::istream& istr, Pack& src) {
        return src.read(istr);
    };
}