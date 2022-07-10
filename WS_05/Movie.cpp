#include "Movie.h"
using namespace sdds;
namespace sdds {
	std::string Movie::trim(std::string str) {
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		std::string  l_title, l_year, l_desc;
		size_t start = 0, end;
		end = strMovie.find(',');
		l_title = strMovie.substr(start, end - start);
		m_title = trim(l_title);

		start = end + 1;
		end = strMovie.find(',', start);
		l_year = strMovie.substr(start, end - start);
		m_year = std::stoi(trim(l_year));

		start = end + 1;
		end = strMovie.length();
		l_desc = strMovie.substr(start, end - start);
		m_description = trim(l_desc);

	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.m_title << " | ";
		os << std::setw(4) << movie.m_year << " | ";
		os << movie.m_description << std::endl;
		return os; 
	}
}
