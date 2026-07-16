# 🗄️ Hash Table Implementations in C++

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=flat-square&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data%20Structures-Hash%20Tables-brightgreen?style=flat-square)

A robust, object-oriented C++ project demonstrating the implementation and performance analysis of two fundamental Hash Table collision resolution techniques: **Separate Chaining** and **Open Addressing**.

This repository was built to showcase a deep understanding of core data structures, memory management, polymorphism, and algorithmic complexity in C++.

## 🚀 Features

- **Polymorphic Design**: Utilizes an abstract base class (`HashTable`) to enforce a unified interface for all collision resolution strategies.
- **Separate Chaining**: Implements `HashTable_Chaining` using `std::vector` and `std::list` to handle collisions gracefully.
- **Open Addressing**: Implements `HashTable_OpenAddressing` to handle collisions directly within the array slots.
- **Dynamic Performance Profiling**: The driver program (`main.cpp`) tracks and reports crucial metrics on-the-fly:
  - Maximum collision chain length / maximum probe sequence length.
  - Average collision chain length / average probe sequence length.
- **Reproducible Testing**: Built-in deterministic testing using a seeded random number generator (`std::mt19937`).

## 📊 Complexity Analysis

| Operation | Average Case | Worst Case |
| :--- | :---: | :---: |
| **Insert** | $O(1)$ | $O(N)$ |
| **Find/Search** | $O(1)$ | $O(N)$ |

*Note: Worst-case scenarios assume a poor hash function where all keys hash to the same bucket (Chaining) or trigger maximum probing (Open Addressing).*

## 🛠️ Project Architecture

```text
├── HashTable.h                       # Abstract base interface
├── HashTable_Chaining.h / .cpp       # Separate Chaining implementation
├── HashTable_OpenAddressing.h / .cpp # Open Addressing implementation
├── Types.h                           # Core data structures (User, Slot)
└── main.cpp                          # Entry point and performance profiler
```

## 💻 Getting Started

### Prerequisites
A modern C++ compiler (C++11 or higher) such as `g++`, `clang++`, or MSVC.

### Compilation (Command Line)
You can quickly compile the project from the terminal using `g++`:

```bash
g++ DataStructures_Programming_Exercise_HashTables/*.cpp -o hashtable_test
```
*(Alternatively, open the provided `.slnx` / `.vcxproj` files in Visual Studio).*

### Execution
The program expects 4 space-separated arguments from standard input:
`[Table_Type] [Table_Size_m] [Number_of_Inserts_N] [Random_Seed]`

* `Table_Type`: `Chaining` or `OpenAddressing`
* `Table_Size_m`: The size of the hash table.
* `Number_of_Inserts_N`: Number of items to insert (`N` $\le$ `m` for Open Addressing).
* `Random_Seed`: Integer seed for the random number generator.

**Example Usage:**
```bash
echo "Chaining 100 50 42" | ./hashtable_test
```
*Outputs the total insertions, current size, max/average chain lengths, and search results.*
