/*Name: Chongpu Zhao
Email : czhao49@myseneca.ca
Student ID : 105054217
Date : 6/12/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <iostream>
namespace sdds {
	template <typename T>
	class Collection
	{
		std::string m_name{};
		T* m_item{ nullptr };
		size_t m_size{ 0 };
		void (*m_observ)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const std::string& name) {
			m_name = name;
			delete[] m_item;
			m_item = nullptr;
			m_size = 0;
			m_observ = nullptr;
		}
		Collection& operator = (const Collection<T>& other) = delete;
		Collection(const Collection<T>& other) = delete;
		~Collection() {
			delete[] m_item;
			m_item = nullptr;
		}
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observ = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool l_flag = true;
			for (size_t i = 0; i < m_size; i++) {
				if (m_item[i].title() == item.title()) {
					l_flag = false;
					break;
				}
			}
			if (l_flag) {
				if (m_size == 0) {
					m_size++;
					m_item = new T[m_size];
					m_item[0] = item;
				}
				else {
					/*T* t_item = new T[m_size];
					for (size_t i = 0; i < m_size; i++) {
						t_item[i] = m_item[i];
					}
					delete[] m_item;
					m_size++;
					m_item = new T[m_size];
					for (size_t i = 0; i < m_size - 1; i++) {
						m_item[i] = t_item[i];
					}
					delete[] temp;
					m_item[m_size - 1] = item;
					if (m_observ != nullptr) {
						m_observ(*this, item);
					}*/
					
					m_size++;
					T* temp = new T[m_size];
					for (size_t i = 0; i < m_size-1; i++) {
						temp[i] = m_item[i];
					}
					delete[] m_item;
					temp[m_size-1] = item;
					m_item = temp;

					if (m_observ != nullptr) {
						m_observ(*this, item);
					}
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx < m_size && idx >= 0) {
				return m_item[idx];
			}
			else {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_size) + "] items.");
			}
		}
		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++) {
				if (m_item[i].title() == title) {
					return &m_item[i];
				}
			}
			return nullptr;
		}
		friend std::ostream& operator<<(std::ostream& os, Collection& colle) {
			for (size_t i = 0; i < colle.size(); i++) {
				os << colle.m_item[i];
			}
			return os;
		}
	};
}
#endif // !SDDS_COLLECTION_H



