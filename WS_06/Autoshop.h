#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include <vector>
#include <list>
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& os) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); ++i) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif // !SDDS_AUTOSHOP_H 


