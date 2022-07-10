#include "ConfirmOrder.h"
using namespace sdds;
namespace sdds {
	ConfirmOrder::ConfirmOrder()
	{
		m_toyNUM = 0;
	}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& order) {
		*this = order;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& order) {
		*this = std::move(order);
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& order) {
		if (this != &order) {
			m_toyNUM = order.m_toyNUM;
			delete[] m_toys;
			m_toys = new const Toy * [m_toyNUM];
			for (size_t i = 0; i < m_toyNUM; i++) {
				m_toys[i] = order.m_toys[i];
			}
		}
		return *this;
	}
	void ConfirmOrder::Empty() {
		this->m_toys = nullptr;
		this->m_toyNUM = 0;
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& order) {
		if (this != &order) {
			delete[] m_toys;
			m_toys = order.m_toys;
			m_toyNUM = order.m_toyNUM;
			order.Empty();
		}
		return *this;
	}
	ConfirmOrder::~ConfirmOrder() {
		//delete[] m_toys;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		bool t_flag = true;
		for (size_t i = 0; i < m_toyNUM; i++) {
			if (&toy == m_toys[i]) {
				t_flag = false;
				break;
			}
		}
		if (t_flag) {
			const Toy** temp = new const Toy * [m_toyNUM + 1];
			for (size_t i = 0; i < m_toyNUM; i++) {
				temp[i] = m_toys[i];
			}
			if (m_toys != nullptr) {
				delete[] m_toys;
			}
			m_toys = temp;
			temp[m_toyNUM] = &toy;
			m_toyNUM++;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		for (size_t i = 0; i < m_toyNUM; i++) {
			if (&toy == m_toys[i]) {
				m_toys[i] = nullptr;
				//m_toyNUM--;
				break;
			}
		}
		return *this;
	}
	std::ostream& ConfirmOrder::display(std::ostream& os) const {
		os << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (m_toyNUM > 0) {
			for (size_t i = 0; i < m_toyNUM; i++) {
				if (m_toys[i] != nullptr) {
					os << *m_toys[i];
				}
			}
		}
		else {
			os << "There are no confirmations to send!\n";
		}
		os << "--------------------------\n";
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order) {
		return order.display(os);
	}
}
