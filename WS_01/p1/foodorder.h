#pragma once
#ifndef  SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <string>
/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : May 22
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder
	{
	private:
		char m_name[10];
		char *m_description = nullptr;
		double m_price;
		bool m_dailyspeical;
		void setEmpty();
	public:
		FoodOrder();
		~FoodOrder();
		FoodOrder(FoodOrder& cpy);
		FoodOrder& operator =(const FoodOrder&cpy);		
		void read(std::istream& is);
		void display() const;
	};
}
#endif // ! SDDS_FOODORDER_H




