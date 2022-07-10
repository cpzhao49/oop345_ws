#include "Car.h"
using namespace sdds;
namespace sdds {
	std::string Car::trim(std::string str) {
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
		return str;
	}
	Car::Car(std::istream& is) {
		std::string l_tag;
		std::string l_maker;
		std::string l_condition;
		std::string l_speed;

		/*std::getline(is, l_tag, ',');
		m_tag = trim(l_tag);*/
		
		std::getline(is, l_maker, ',');
		m_maker = trim(l_maker);
		
		std::getline(is, l_condition, ',');
		m_condition = trim(l_condition);
		if(m_condition == "n" || m_condition == "N" || m_condition == "" || m_condition == " ") {
			m_condition = "new";
		}
		else if(m_condition == "u" || m_condition == "U") {
			m_condition = "used";
		}
		else if(m_condition == "b" || m_condition == "B") {
			m_condition = "broken";
		}
		else {
			std::string error = "Invalid record!";
			throw error;
		}
		
		std::getline(is, l_speed, ',');
		try {
			m_topspeed = std::stod(trim(l_speed));
		}
		catch (...) {
			std::string error = "Invalid record!";
			throw error;
		}
		
	}
	std::string Car::condition() const {
		return m_condition;
	}
	double Car::topSpeed() const {
		return m_topspeed;
	}
	void Car::display(std::ostream& os) const { 
		os << "| " << std::setw(10) << std::right << m_maker << " | "; 
		os << std::setw(6) << std::left << m_condition << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}