#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>
#include "SpellChecker.h"
namespace sdds {
	class Movie
	{
		std::string m_title{}; 
		size_t m_year{}; 
		std::string m_description{};
		std::string trim(std::string str);
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling (T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator <<(std::ostream& os, const Movie& movie);		
	};
}
#endif // !SDDS_MOVIE_H



