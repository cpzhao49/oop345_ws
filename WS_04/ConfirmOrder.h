#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include "Toy.h"
using namespace sdds;
namespace sdds {
	class ConfirmOrder
	{
		const Toy** m_toys = nullptr;
		size_t m_toyNUM;
	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& order);
		ConfirmOrder(ConfirmOrder&& order);
		ConfirmOrder& operator=(const ConfirmOrder& order);
		ConfirmOrder& operator=(ConfirmOrder&& order);
		~ConfirmOrder();
		void Empty();
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		std::ostream& display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
}

#endif // !SDDS_CONFIRMORDER_H



