#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include "Toy.h"
using namespace sdds;
namespace sdds {
	class Child
	{
		std::string m_name;
		int m_age;
		size_t m_toyNUM;
		const sdds::Toy** m_toys = nullptr;
	public:
		Child();
		Child(Child&& child);
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& child);
		Child& operator = (const Child& child);
		Child& operator =(Child&& child);
		~Child();
		size_t size() const;
		std::ostream& display(std::ostream& os) const;
	};
	std::ostream& operator << (std::ostream& os, const Child& child);
}
#endif // !SDDS_CHILD_H



