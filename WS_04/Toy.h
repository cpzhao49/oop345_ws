#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>
namespace sdds {
	class Toy
	{
		unsigned int m_orderID;
		std::string m_toyName;
		unsigned int m_toyNUM;
		double m_price;
		const double m_tax = 0.13;
	public:
		Toy();
		Toy(const Toy& toy);
		~Toy() {};
		void update(int numItems);
		Toy& operator = (const Toy& toy);
		Toy(const std::string& toy);
		std::ostream& display(std::ostream& os) const;
	private:
		std::string& trim(std::string& str);
	};
	std::ostream& operator<<(std::ostream& os, const Toy& toy);
}
#endif // !SDDS_TOY_H



