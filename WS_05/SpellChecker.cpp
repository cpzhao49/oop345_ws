#include "SpellChecker.h"
using namespace sdds;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			std::string fileLine;
			size_t i = 0;
			while (file && i < 6) {
				getline(file, m_badWords[i], ' ');
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
				getline(file, m_goodWords[i], '\n');
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				i++;
			}
			file.close();
		}
	}
	void SpellChecker::operator()(std::string& text) {
		for (int i = 0; i < 6; ++i) {
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				m_correctWord[i]++;
			}			
		}
	}
	void SpellChecker::showStatistics(std::ostream & out) const {
		out << "Spellchecker Statistics\n";
		for (int i = 0; i < 6; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_correctWord[i] << " replacements" << std::endl;
		}
	}
}
