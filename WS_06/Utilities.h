#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
#include <iostream>
#include <sstream>
namespace sdds {  
	Vehicle* createInstance(std::istream& is);
}
#endif

