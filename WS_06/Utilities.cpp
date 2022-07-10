#include "Utilities.h"
#include "Car.h"
namespace sdds {
	Vehicle* createInstance(std::istream& is) {
		char delimiter = '\n';
		char first_char;
		std::string input;
		std::getline(is, input);
		std::stringstream ss(input);
		ss >> first_char >> delimiter;
		if (ss) {
			switch (first_char) {
			case 'c':
				return new Car(ss);
				break;
			case 'C':
				return new Car(ss);
				break;
			case 'r':
				return new Racecar(ss);
				break;
			case 'R':
				return new Racecar(ss);
				break;
			default:
				throw first_char;
			}
		}
		return nullptr;
	}
}
