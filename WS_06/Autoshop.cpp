#include "Autoshop.h"
namespace sdds{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle); 
		return *this; 
	}
	void Autoshop::display(std::ostream& os) const { 
		os << "--------------------------------\n| Cars in the autoshop!        |\n--------------------------------\n"; 
		for (size_t i = 0; i < m_vehicles.size(); i++) { 
			if (m_vehicles[i]->condition() != "") {
				m_vehicles[i]->display(os); 
				os << std::endl; } 
		}
		os << "--------------------------------" << std::endl; 
	}
	Autoshop::~Autoshop() {
		for (size_t i = 0; i < m_vehicles.size(); i++) {
			delete m_vehicles[i]; 
		} 
	}
}