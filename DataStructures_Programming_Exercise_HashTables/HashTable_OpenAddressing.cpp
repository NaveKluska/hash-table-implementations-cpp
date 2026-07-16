#include "HashTable_OpenAddressing.h"
#include <iostream>

int HashTable_OpenAddressing::h(const int key, const size_t i) const
{ 
    return (h0(key) + i) % m;
}

void HashTable_OpenAddressing::Init(const int m)
{
	table.resize(m);
	this->m = m;

	n = 0;
	maxTry = 0;
	totalTries = 0;
}

int HashTable_OpenAddressing::Insert(const int key, const std::string data)
{
	for (size_t i = 0; i < m; i++)
	{
		size_t h_key = h(key, i);

		// Check if key already exists
		if (table[h_key].occupied && table[h_key].user.key == key)
			return -1;

		// Found empty slot - insert here
		if (!table[h_key].occupied)
		{
			table[h_key].user = { key, data }; // insert user
			table[h_key].occupied = true;  // Mark as occupied!

			n++;

			if (i + 1 > maxTry) 
				maxTry = i + 1;

			totalTries += i + 1;

			// return number of probes
			return i + 1;
		}
	}

	// Table full (shouldn't happen per assignment)
	return -1;
}

int HashTable_OpenAddressing::Find(const int key) const
{
	for (size_t i = 0; i < m; i++)
	{
		size_t h_key = h(key, i);
		
		// Empty slot means key doesn't exist
		if (!table[h_key].occupied)
		{
			std::cout << "Not found";
			return i + 1;
		}
		
		// Found the key
		if (table[h_key].user.key == key)
		{
			std::cout << "(" << table[h_key].user.key << ", " << table[h_key].user.data << ")";
			return i + 1;
		}
	}

	// Table full, key not found
	std::cout << "Not found";
	return m;
}

size_t HashTable_OpenAddressing::size() const
{
	return n;
}

size_t HashTable_OpenAddressing::Max_Length() const
{
	return maxTry;
}

double HashTable_OpenAddressing::Average_Length() const
{
	// avoid division by zero - need to address the teacher about this
	// since this was not told in the exercise
	// Update: In the mama tests it treats average length as -1 when n=0
	if (n == 0)
		return -1; // Changed to -1 based on test requirements
	return (double)totalTries / n;
}

