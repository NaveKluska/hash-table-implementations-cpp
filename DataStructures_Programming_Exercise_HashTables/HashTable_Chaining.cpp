#include "HashTable_Chaining.h"
#include <iostream>

//	resize table to m
void HashTable_Chaining::Init(const int m)
{
	table.resize(m);
	this->m = m;

	n = 0;
	maxLengthList = 0;
}

int HashTable_Chaining::Insert(const int key, const std::string data)
{
	int h0_key = h0(key);

	// traverse through each node in the list 
	for (const User& user : table[h0_key])
	{
		// if user already in the table
		if (key == user.key)
			return -1;
	}

	User newUser{ key, data };

	table[h0_key].push_back(newUser);
	n++;	

	if (table[h0_key].size() > maxLengthList)
		maxLengthList = table[h0_key].size();

	return table[h0_key].size();
}

int HashTable_Chaining::Find(const int key) const
{
	int h0_key = h0(key);

	int position = 1; 
	for (const User& user : table[h0_key]) 
	{
		// check if found, return position
		if (key == user.key)
		{
			std::cout << "(" << user.key << ", " << user.data << ")";
			return position;
		}
		position++;
	}

	std::cout << "Not found";
	return position-1;
}

size_t HashTable_Chaining::size() const
{
	return n;
}

size_t HashTable_Chaining::Max_Length() const
{
	return maxLengthList;
}

double HashTable_Chaining::Average_Length() const
{
	// avoid division by zero - need to address the teacher about this
	// since this was not told in the exercise
	// Update: In the mama tests it treats average length as -1 when m = 0
	if (m == 0) 
		return -1; // Changed to -1 based on test requirements
	return (double)n / m;
}
