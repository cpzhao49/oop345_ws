#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[6]; 
		std::string m_goodWords[6];
		int m_correctWord[6] = {0};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

}
#endif // !SDDS_SPELLCHECKER_H


