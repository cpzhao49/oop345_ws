#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <iomanip>
#include <string>
namespace sdds {
	class Book {
		std::string m_title = "";
		std::string m_author = "";
		std::string m_country = "";
		size_t *m_year = nullptr;
		double *m_price = nullptr;
		std::string m_description = "";
	public:
		Book() {};
		std::string trim(std::string str);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price() const;
		std::ostream& display(std::ostream& os) const;
		Book(const std::string& strBook);
	};
	std::ostream& operator << (std::ostream& os, const Book& book);
}
#endif


