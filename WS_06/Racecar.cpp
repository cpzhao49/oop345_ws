#include "Racecar.h"
namespace sdds {
	Racecar::Racecar(std::istream& in): Car(in) {
		std::string l_booster; 
		std::getline(in, l_booster, ',');
		m_booster = std::stod(Car::trim(l_booster));
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}