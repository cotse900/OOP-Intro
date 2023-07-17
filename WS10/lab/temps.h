/*
    OOP244 Workshop 10
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 13 Apr 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include <iostream>
#include "Collection.h"

using namespace std;
namespace sdds
{
    //This template receives array, array size, and a constant referenced Collection object. It looks for matching elements between the array and the object. If the two have a matching element with the overloaded == operator in each required array (Car, Employee, Student, int), then the "match" increments and it is the required matching array size. Then, in another loop, use the Collection object S with array size "match", and try to set S elements to the number of "matched" corresponding to the required arrays. Select returns the matched set of elements of this object as S.
    template <typename T>
    Collection<T> select(const T arr[], int arrSize, const T& obj) {
        int match = 0;
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] == obj) {
                match++;
            }
        }
        int matched = 0;
        Collection<T>S(match);
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] == obj) {
                S[matched] = arr[i];
                matched++;
            }
        }
        return S;
    }
    //This template receives the Collection object and prints a required array's title. It goes through to print each matched element of the object each line through using select above. For each given object, call size() to invoke m_size in Collection which reflects matching elements (through = operator in Collection). Notice the array size is unsigned as in Connection.
    template <typename T>
    void printCollection(const Collection<T>& object, const char* title) {
        
        cout << title << endl;
        for (unsigned i = 0; i < object.size(); i++) {
            cout << object[i] << endl;
        }
    }
}
#endif //!SDDS_TEMPS_H