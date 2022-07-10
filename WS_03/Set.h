/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : 6/5/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <string>
#include <cmath>
#include "Pair.h"
#include "Collection.h"
using namespace sdds;
namespace sdds {
    template<class T>
    class Set : public Collection<T, 100> {
        const unsigned int CAPACITY = 100;
    public:
        Set() {};
        bool add(const T& obj) override {
            for (unsigned int i = 0; i < this->size(); i++) {
                if (obj == this->arr[i]) {
                    return false;
                }
            }
            return Collection<T, 100>::add(obj);
        }
    };

    template<>
    class Set<double> : public Collection<double, 100> {
        const unsigned int CAPACITY = 100;
    public:
        Set() {};
        bool add(const double& obj)  override {
            for (unsigned int i = 0; i < size(); i++) {
                if (std::fabs(obj - this->arr[i]) <= 0.01) {
                    return false;
                }
            }
            return Collection<double, 100>::add(obj);
        }
    };
}
#endif // ! SDDS_SET_H