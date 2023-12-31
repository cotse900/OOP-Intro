/*
    OOP244
    Name   : Chungon Tse
    ID     : 154928188
    Email  : cotse@myseneca.ca
    Section: NDD
    Date   : 13 Apr 2022
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*------------------------------------------------------
Workshop 10 part 1
Module: Collection
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

namespace sdds {
   template <class type>
   class Collection {
      type* m_objs{};
      unsigned m_size{};
   public:
      Collection(unsigned size=0) :m_size( size ) {
         if(size) m_objs = new type[size];
      }
      Collection(const Collection<type>& S) {
         operator=(S);
      }
      Collection<type>& operator=(const Collection<type>& S) {
         delete[] m_objs;
         m_size = 0;
         if (S.m_size && this != &S) {
            m_objs = new type[m_size = S.m_size];
            for (unsigned i = 0; i < m_size; i++)  m_objs[i] = S.m_objs[i];
         }
         return *this;
      }
      virtual ~Collection() {
         delete[] m_objs;
      }
      unsigned size()const {
         return m_size;
      }
      type& operator[](unsigned i) {
         return m_objs[i % m_size];
      }
      const type& operator[](unsigned i)const {
         return m_objs[i % m_size];
      }
   };
}
#endif // !

