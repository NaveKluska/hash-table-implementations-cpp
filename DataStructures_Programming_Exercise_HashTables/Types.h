#pragma once
#include <string>

struct User {
	int key;
	std::string data;
};

struct Slot {
	User user;
	bool occupied = false;
};