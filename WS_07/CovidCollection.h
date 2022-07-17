#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <vector>
#include <iostream>
#include <string>
#include <list>
namespace sdds {
	class Covid {
	public:
		Covid() {};
		Covid(const Covid& covid);
		Covid& operator = (const Covid& covid);
		std::string m_country = "";
		std::string	m_city = "";
		std::string m_variant = "";
		size_t	m_cases = 0;
		int	m_year = 0;
		size_t m_deaths = 0;
	};

	class CovidCollection {
		std::vector<Covid> m_covids;
		std::string trim(std::string str);
	public:
		CovidCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(std::string field);
		void cleanList();
		bool inCollection(std::string variant) const;
		std::list<Covid> getListForCountry(std::string country) const;
		std::list<Covid> getListForVariant(std::string variant) const;
			
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H
