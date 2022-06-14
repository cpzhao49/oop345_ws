#include "Book.h"
using namespace sdds;
namespace sdds {
	std::string Book::trim(std::string str) {
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}
	Book::Book(const std::string& strBook) {
		std::string l_author, l_title, l_country, l_price, l_year, l_desc;
		size_t start = 0, end;
		end = strBook.find(',');
		l_author = strBook.substr(start, end - start);
		m_author = std::stoi(trim(l_author));

		start = end + 1;
		end = strBook.find(':', start);
		l_title = strBook.substr(start, end - start);
		m_title = trim(l_title);

		start = end + 1;
		end = strBook.find(':', start);
		l_country = strBook.substr(start, end - start);
		m_country = trim(l_country);

		start = end + 1;
		end = strBook.find(':', start);
		l_price = strBook.substr(start, end - start);
		*m_price = std::stod(trim(l_price));

		start = end + 1;
		end = strBook.find(':', start);
		l_year = strBook.substr(start, end - start);
		*m_year = std::stoi(trim(l_year));

		start = end + 1;
		end = strBook.find(':', start);
		l_desc = strBook.substr(start, end - start);
		m_description = std::stoi(trim(l_desc));

	}
	const std::string& Book::title() const {
		return m_title;
	}
	const std::string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return *m_year;
	}
	double& Book::price() const {
		return *m_price;
	}
	std::ostream& Book::display(std::ostream& os) const {
		os << std::setw(20) << std::right << m_title << " | ";
		os << std::setw(22) << std::right << m_author << " | ";
		os << std::setw(5) << std::right << m_country << " | ";
		os << std::setw(4) << std::right << m_year << " | ";
		os << std::setw(6)
		return os;
	}
	std::ostream& operator << (std::ostream& os, const Book& book) {
		return book.display(os);
	}
}