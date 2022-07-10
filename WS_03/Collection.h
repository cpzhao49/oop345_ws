/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : 6/5/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <type_traits>
#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds {

	template<typename T, unsigned int CAPACITY>
	class Collection {
		unsigned int m_size = 0;
	protected:
		T arr[CAPACITY];
	public:
		Collection() {
			if (std::is_same<T, Pair>::value && CAPACITY == 100) {
				static T obj{ "No Key", "No Value" };
			}
			else {
				static T obj{};
			}
		}
		virtual ~Collection() {}
		unsigned int size() const {
			return m_size;
		}
		void display(std::ostream& os = std::cout) const {
			os << "----------------------\n| Collection Content |\n----------------------\n";
			for (unsigned int i = 0; i < m_size; i++) {
				os << arr[i] << '\n';
			}
			os << "----------------------\n";
		}
		virtual bool add(const T& obj) {
			if (m_size < CAPACITY) {
				arr[m_size] = obj;
				m_size++;
				return true;
			}
			return false;
		}
		T& operator[](unsigned int index) {	
			static T dummy;
			if (index >= 0 && index < m_size) {
				dummy = arr[index];
				return dummy;
			}
			return dummy;
		}
	};
}
#endif // !