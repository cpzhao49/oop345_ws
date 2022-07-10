#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <iomanip>
#include <string>
#include "SpellChecker.h"
namespace sdds {
	class Book {
		std::string m_title = "";
		std::string m_author = "";
		std::string m_country = "";
		size_t m_year=0;
		double m_price=0;
		std::string m_description = "";
		std::string trim(std::string str);
	public:
		Book() {};		
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		std::ostream& display(std::ostream& os) const;
		Book(const std::string& strBook);
		
		template<class T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}
		friend std::ostream& operator << (std::ostream& os, const Book& book);
	};
	
}
#endif


