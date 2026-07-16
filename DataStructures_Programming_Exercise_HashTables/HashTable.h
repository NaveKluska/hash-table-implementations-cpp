#pragma once
#include <vector>
#include <list>
#include <string>

class HashTable {

	protected:
	int m = 0;
	size_t n = 0;

	// h0(key) = key mod m
	int h0(const int key) const { return key % m; }

	public:
	virtual	void Init(const int m) = 0;
	virtual int Insert(const int key, const std::string data) = 0;
	virtual int Find(const int key) const = 0;
	virtual size_t size() const = 0;
	virtual size_t Max_Length() const = 0;
	virtual double Average_Length() const = 0;

	virtual ~HashTable() = default;
};