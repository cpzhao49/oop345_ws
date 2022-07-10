#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include <string>
#include <iostream>
#include <iomanip>
namespace sdds {
	class Car :public Vehicle {
		std::string m_tag = "";
		std::string m_maker = "";
		std::string m_condition = "";
		double m_topspeed = 0;
	public:
		Car() {};
		Car(std::istream& is);
		std::string trim(std::string str);
		std::string condition() const override;
		virtual double topSpeed() const override;
		virtual void display(std::ostream& os) const override;
		virtual ~Car() {} ;			
	};
}
#endif // !SDDS_CAR_H


