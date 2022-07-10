/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : 6/5/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Pair.h"
using namespace sdds;
namespace sdds {
    void Pair::changeContent(std::string key, std::string content) {
        this->m_key = key;
        this->m_value = content;
    }
    std::ostream& Pair::display(std::ostream& os) const {
        os << std::right << std::setw(20) << getKey() << std::left << ": " << getValue();
        return os;
    }
    bool Pair::operator == (Pair& another)const {
        return m_key == another.getKey();
    }
    std::ostream& operator<<(std::ostream& os, const Pair& obj) {
        return obj.display(os);
    }
}
