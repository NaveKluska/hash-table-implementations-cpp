#pragma once
#include "HashTable.h"
#include "Types.h"

class HashTable_OpenAddressing : public HashTable
{
	std::vector<Slot> table;
	size_t maxTry = 0;
	size_t totalTries = 0;

	// h
	int h(const int key, const size_t i) const;

	public:
	void Init(const int m) override;
	int Insert(const int key, const std::string data) override;
	int Find(const int key) const override;
	size_t size() const override;
	size_t Max_Length() const override;
	double Average_Length() const override;
};