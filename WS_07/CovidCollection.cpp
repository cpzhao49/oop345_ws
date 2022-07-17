#include "CovidCollection.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
namespace sdds {
	int debug = 0;
	Covid::Covid(const Covid& covid) {
		if (this != &covid) {
			operator =(covid);
		}
	}
	Covid& Covid::operator = (const Covid& covid) {
		if (this != &covid) {
			m_country = covid.m_country;
			m_city = covid.m_city;
			m_variant = covid.m_variant;
			m_cases = covid.m_cases;
			m_year = covid.m_year;
			m_deaths = covid.m_deaths;
		}
		return *this;
	}
	std::string CovidCollection::trim(std::string str) {
		if (str.find_last_not_of(" ") != std::string::npos) {
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);
			return str;
		}
		return "0";
	}
	CovidCollection::CovidCollection(std::string filename) {
		ifstream file(filename);
		if (file) {
			std::string fileLine;
			do {
				/*std::getline(file, fileLine);
				cout << fileLine << endl;*/
				std::getline(file, fileLine);
				if (file) {
					Covid covid;
					if (debug) {
						std::cout << "fileLine: " << fileLine << std::endl;
						std::cout << fileLine.substr(0, 25) << ":" << trim(fileLine.substr(0, 25)) << std::endl;
						std::cout << (fileLine.substr(25, 25)) << ":" << trim(fileLine.substr(25, 25)) << std::endl;
						std::cout << (fileLine.substr(50, 25)) << ":" << trim(fileLine.substr(50, 25)) << std::endl;
						std::cout << fileLine.substr(75, 5) << ":" << trim(fileLine.substr(75, 5)) << std::endl;
						std::cout << fileLine.substr(80, 5) << ":" << trim(fileLine.substr(80, 5)) << std::endl;
						std::cout << fileLine.substr(85, 5) << ":" << trim(fileLine.substr(85, 5)) << std::endl;
					}
					covid.m_country = trim(fileLine.substr(0, 25));
					covid.m_city = trim(fileLine.substr(25, 25));
					covid.m_variant = trim(fileLine.substr(50, 25));
					covid.m_year = stoi(trim(fileLine.substr(75, 5)));
					covid.m_cases = (size_t)stoi(trim(fileLine.substr(80, 5)));
					covid.m_deaths = (size_t)stoi(trim(fileLine.substr(85, 5)));
					m_covids.push_back(covid);
				}
			} while (file);

		}
		else {
			throw std::string("Invalid Fail Name\n");
		}
	}
	void CovidCollection::display(std::ostream& out) const {
		size_t total_death = 0;
		size_t total_cases = 0;
		for_each(m_covids.begin(), m_covids.end(),
			[&](Covid covid)->void {
				total_death += covid.m_deaths;
				total_cases += covid.m_cases;
				out << covid << "\n"; }
		);
		out << setw(89) << setfill('-') << '\n'
	 << setfill(' ') << "|" << setw(79) << "Total Cases Around the World: " << setw(6) << total_cases << " |\n" 
			<< "|" << setw(79) << "Total Deaths Around the World: " << setw(6) << total_death << " |\n";
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| " << setw(20) << left << theCovid.m_country << "  | "
			<< setw(15) << theCovid.m_city << " | "
			<< setw(20) << theCovid.m_variant << " | "
			<< setw(6) << right;
		if (theCovid.m_year > 0) { out << theCovid.m_year; }
		else { out << " "; }
		out << " | "
			<< setw(4) << right << theCovid.m_cases << " | "
			<< setw(3) << right << theCovid.m_deaths << " |";
		return out;
	}
	void CovidCollection::sort(std::string field) {
		if (field == "country") {
			std::sort(m_covids.begin(), m_covids.end(), [](const Covid& a, const Covid& b) -> bool { return a.m_country < b.m_country; });
		}
		else if (field == "variant") {
			
			std::sort(m_covids.begin(), m_covids.end(), [](const Covid& a, const Covid& b) -> bool { return a.m_variant < b.m_variant; });
			std::vector<Covid> alter_covids(m_covids.size());

		}
		else if (field == "cases") {
			std::sort(m_covids.begin(), m_covids.end(), [](const Covid& a, const Covid& b) -> bool { return a.m_cases < b.m_cases; });
			//std::partial_sort(m_covids.begin(), m_covids.end(), m_covids.end(), [](const Covid& a, const Covid& b) -> bool { return a.m_cases < b.m_cases; });
		}
		else if (field == "deaths") {
			std::sort(m_covids.begin(), m_covids.end(), [](const Covid& a, const Covid& b) -> bool { return a.m_deaths < b.m_deaths; });
			//std::vector<Covid> alter_covids(m_covids.size());
			//partial_sort_copy(m_covids.begin(), m_covids.end(), alter_covids.begin(), alter_covids.end(), [](const Covid& a, const Covid& b) -> bool { return a.m_deaths < b.m_deaths; });
			//m_covids = alter_covids;
		}
	}
	void CovidCollection::cleanList() {
		Covid newcovid;
		replace_if(m_covids.begin(), m_covids.end(),
			[&](const Covid& covid) {
				newcovid = covid;
				if (newcovid.m_variant == "[None]") {
					newcovid.m_variant = "";
				}
				return covid.m_variant == "[None]"; },
			newcovid
					);
	}
	bool CovidCollection::inCollection(std::string variant) const {
		return  any_of(m_covids.begin(), m_covids.end(), [&](Covid cov) { return cov.m_variant == variant; });
	}
	std::list<Covid> CovidCollection::getListForCountry(std::string country) const {
		std::list<Covid> newCovidList(m_covids.begin(), m_covids.end());
		remove_if(newCovidList.begin(), newCovidList.end(), [&](Covid covid) {return covid.m_country != country; });

		return newCovidList;
	}
	std::list<Covid> CovidCollection::getListForVariant(std::string variant) const {
		int size = count_if(m_covids.begin(), m_covids.end(), [&](const Covid& covid) {
			return covid.m_variant == variant;
			}
		);
		list <Covid> newlist(size);
		copy_if(m_covids.begin(), m_covids.end(), newlist.begin(), [&](const Covid& covid) {
			return covid.m_variant == variant;
			});
		return newlist;
	}
} // namespace sdds