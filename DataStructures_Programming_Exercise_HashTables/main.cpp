#include "HashTable.h"
#include <iostream>
#include "HashTable_Chaining.h"
#include "HashTable_OpenAddressing.h"
#include <random>
#include <cstdio>

using namespace std;

int main()
{
	string Table_Type;
	int m;
	int N;
	int seed;

	// Read input and check if stream is valid
	if (!(cin >> Table_Type >> m >> N >> seed))
	{
		cout << "wrong input" << endl;
		return 0;
	}

	// Validate m (must be positive)
	if (m <= 0)
	{
		cout << "wrong input" << endl;
		return 0;
	}

	// Validate N (must be non-negative)
	if (N < 0)
	{
		cout << "wrong input" << endl;
		return 0;
	}

	// Validate Table_Type
	if (Table_Type != "Chaining" && Table_Type != "OpenAddressing")
	{
		cout << "wrong input" << endl;
		return 0;
	}

	// For OpenAddressing: N must be <= m
	if (Table_Type == "OpenAddressing" && N > m)
	{
		cout << "wrong input" << endl;
		return 0;	
	}

	// Design choice: I used a pointer and a dynamic allocation because of
	// dangling references bug if I had used a stack allocation with polymorphism
	HashTable* table = nullptr;

	// Initialize appropriate table type
	if (Table_Type == "Chaining")
	{
		table = new HashTable_Chaining();
	}
	else
	{
		table = new HashTable_OpenAddressing();
	}

	// Resize table to size m
	table->Init(m);

	// Initialize random number generator with given seed
	std::mt19937 rng(seed);

	// Insert N random users
	cout << "Inserts:" << endl;
	for (int i = 0; i < N; i++)
	{
		int key = rng() % 1000000;                        // Generate random key
		std::string name = "User" + std::to_string(key);  // Create username
		cout << table->Insert(key, name) << endl;         // Print Insert return value
	}
	
	// Print size
	cout << "Size:" << endl;
	cout << table->size() << endl;
	// Print max length of chains / max probes
	cout << "Max length:" << endl;
	cout << table->Max_Length() << endl;
	// Print average length of chains / average probes in floating point format with 4 decimal places
	cout << "Average length:" << endl;
	printf("%.4f\n", table->Average_Length());
	// Find user with key 100
	cout << "Find(100):" << endl;
	int result = table->Find(100);
	cout << endl << result << endl;
	
	// Free allocated memory
	delete table;

	return 0;
}