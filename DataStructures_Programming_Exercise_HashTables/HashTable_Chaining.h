#pragma once
#include "HashTable.h"
#include "Types.h"

class HashTable_Chaining : public HashTable 
{
	std::vector<std::list<User>> table;
	size_t maxLengthList = 0;

	public:
	void Init(const int m) override;
	int Insert(const int key, const std::string data) override;
	int Find(const int key) const override;
	size_t size() const override;
	size_t Max_Length() const override;
	double Average_Length() const override;
};