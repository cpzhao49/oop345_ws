#pragma once
#include <cstring>
namespace sdds {
	class ProteinDatabase
	{
		int m_proteinNum;
		std::string * m_proteins;		
	public:
		ProteinDatabase();
		ProteinDatabase(const char* filename);
		size_t size();
		std::string operator[](size_t);
	};
}


