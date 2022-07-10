/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : 6/5/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <string>
#include <iostream>
namespace sdds {
    class Pair
    {
        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() const { return m_key; }
        const std::string& getValue() const { return m_value; }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
        void changeContent(std::string key, std::string content);
        Pair() : m_key{ "NK" }, m_value{ "NV" }{};
        std::ostream& display(std::ostream& os = std::cout)const;
        bool operator == (Pair& another)const;
    };
    std::ostream& operator<<(std::ostream& os, const Pair& obj);
}
#endif // !SDDS_PAIR_H
