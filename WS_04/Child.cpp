#include "Child.h"
using namespace sdds;
namespace sdds {
	Child::Child() {
		m_name = "";
		m_age = 0;
		m_toyNUM = 0;
	}
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
		m_toys = new const Toy * [count];
		for (size_t i = 0; i < count; i++) {
			m_toys[i] = new Toy(*toys[i]);
		}
		m_name = name;
		m_age = age;
		m_toyNUM = count;
	}
	Child::Child(const Child& child) {
		*this = child;
	}
	Child& Child::operator = (const Child& child) {
		if (this != &child) {
			delete[] m_toys;
			m_toys = new const Toy * [child.m_toyNUM];
			for (size_t i = 0; i < child.m_toyNUM; i++) {
				if (child.m_toys[i] != nullptr) {
					m_toys[i] = new const Toy(*(child.m_toys[i]));
				}
				else {
					m_toys[i] = nullptr;
				}
			}
			m_name = child.m_name;
			m_age = child.m_age;
			m_toyNUM = child.m_toyNUM;
		}
		return *this;
	}
	Child::Child(Child&& child) {
		*this = std::move(child);
	}
	Child& Child::operator =(Child&& child) {
		//std::cout << "moved";
		if (this != &child) {
			if (m_toys != nullptr) {
				for (size_t i = 0; i < m_toyNUM; i++) {
					delete m_toys[i];
				}
				delete[] m_toys;
			}
			m_toys = child.m_toys;
			m_name = child.m_name;
			m_age = child.m_age;
			m_toyNUM = child.m_toyNUM;
			child.m_toys = nullptr;
			child.m_age = 0;
			child.m_name = "";
			child.m_toyNUM = 0;
		}
		return *this;
	}
	Child::~Child() {
		for (size_t i = 0; i < m_toyNUM; i++) {
			delete m_toys[i];
		}
		delete[] m_toys;
		m_toys = nullptr;
	}
	size_t Child::size() const {
		return m_toyNUM;
	}
	std::ostream& Child::display(std::ostream& os) const {
		static size_t s_count = 1;
		os << "--------------------------\nChild " << s_count << ": " << m_name << " " << m_age << " years old:\n--------------------------\n";
		if (m_toyNUM == 0) {
			os << "This child has no toys!\n";
		}
		else {
			for (size_t i = 0; i < m_toyNUM; i++) {
				m_toys[i]->display(os);
			}
		}
		os << "--------------------------\n";
		s_count++;
		return os;
	}
	std::ostream& operator << (std::ostream& os, const Child& child) {
		return child.display(os);
	}
}
