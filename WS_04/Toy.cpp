#include <iomanip>
#include "Toy.h"
using namespace sdds;
namespace sdds {
	Toy::Toy() {
		m_orderID = 0;
		m_toyName = "";
		m_price = 0.0;
		m_toyNUM = 0;
	}
	Toy::Toy(const Toy& toy) {
		m_orderID = toy.m_orderID;
		m_toyName = toy.m_toyName;
		m_price = toy.m_price;
		m_toyNUM = toy.m_toyNUM;
	}
	void Toy::update(int numItems) {
		m_toyNUM = numItems;
	}
	Toy& Toy::operator = (const Toy& toy) {
		m_orderID = toy.m_orderID;
		m_toyName = toy.m_toyName;
		m_toyNUM = toy.m_toyNUM;
		m_price = toy.m_price;
		return *this;
	}
	std::string& Toy::trim(std::string& str) {
		/*		size_t post = str.find(' ');
		while (post != (size_t)-1) {
			str.erase(post, 1);
			post = str.find(' ');
		}
		return str;*/
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}
	Toy::Toy(const std::string& toy) {
		std::string t_id;
		std::string t_name;
		std::string t_num;
		std::string t_price;

		size_t start = 0;
		size_t end = 0;

		end = toy.find(':');
		t_id = toy.substr(start, end - start);
		m_orderID = std::stoi(trim(t_id));

		start = end + 1;
		end = toy.find(':', start);
		t_name = toy.substr(start, end - start);
		m_toyName = trim(t_name);

		start = end + 1;
		end = toy.find(':', start);
		t_num = toy.substr(start, end - start);
		m_toyNUM = std::stoi(trim(t_num));

		start = end + 1;
		end = toy.find(':', start);
		t_price = toy.substr(start, end - start);
		m_price = std::stod(trim(t_price));
	}
	std::ostream& Toy::display(std::ostream& os) const {
		os << "Toy";
		os << std::setw(8) << std::right << m_orderID << ':';
		os << std::setw(18) << std::right << m_toyName;
		os << std::setw(3) << std::right << m_toyNUM << " items";
		os << std::setw(8) << std::right << m_price << "/item  subtotal:";
		os << std::setw(7) << std::right << std::setprecision(2) << std::fixed << m_toyNUM * m_price;
		os << " tax:" << std::setw(6) << std::right << std::setprecision(2) << std::fixed << (m_toyNUM * m_price) * 0.13;
		os << " total:" << std::setw(7) << std::right << std::setprecision(2) << std::fixed << (m_toyNUM * m_price) * 1.13 << std::endl;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Toy& toy) {
		return toy.display(os);
	}
}
