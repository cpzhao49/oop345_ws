/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : May 22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "foodorder.h"
using namespace sdds;
using namespace std;

double g_taxrate;
double g_dailydiscount;

namespace sdds {
	static int s_count = 0;
	FoodOrder::FoodOrder() {
		setEmpty();
	}
	FoodOrder::~FoodOrder() {
		if (m_description != nullptr) {
			delete[] m_description;
			m_description = nullptr;
		}
	}
	void FoodOrder::setEmpty() {
		m_price = 0;
		strcpy(m_name, "");
		if (m_description != nullptr) {
			delete[]m_description;
			m_description = nullptr;
		}
		m_dailyspeical = false;
	}
	FoodOrder::FoodOrder(FoodOrder& cpy) {
		strcpy(m_name, cpy.m_name);
		m_description = new char[strlen(cpy.m_description) + 1];
		strcpy(m_description, cpy.m_description);
		m_price = cpy.m_price;
		m_dailyspeical = cpy.m_dailyspeical;
	}
	FoodOrder& FoodOrder::operator =(const FoodOrder& cpy) {
		setEmpty();
		strcpy(m_name, cpy.m_name);
		m_description = new char[strlen(cpy.m_description) + 1];
		strcpy(m_description, cpy.m_description);
		m_price = cpy.m_price;
		m_dailyspeical = cpy.m_dailyspeical;
		return *this;
	}
	void FoodOrder::read(istream& is) {
		setEmpty();
		is.get(m_name, 10, ',');
		is.ignore();
		string t_description;
		getline(is, t_description, ',');
		m_description = new char[strlen(t_description.c_str()) + 1];
		strcpy(m_description, t_description.c_str());
		is >> m_price;
		is.ignore();
		if (is.peek() == 'Y') {
			m_dailyspeical = true;			
		}
		else {
			m_dailyspeical = false;
		}
		is.ignore(100, '\n');

	}
	void FoodOrder::display() const {
		s_count++;
		if (strcmp(m_name, "") == 0) {
			cout << left << setw(2) << s_count << ". No Order" << endl;
		}
		else {
			cout  <<left << setw(2) <<  s_count << ". " << left << setw(10) << m_name << "|"
				<< left << setw(25) << m_description << "|"
				<< left << setw(12) << fixed << setprecision(2) << m_price*(1+g_taxrate) << "|";
			if (m_dailyspeical) {
				cout << right << setw(13) << fixed << setprecision(2) << m_price * (1 + g_taxrate) - g_dailydiscount;
			}
			cout << endl;
		}
	}
}
