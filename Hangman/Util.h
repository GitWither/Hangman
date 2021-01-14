#pragma once

#include <string>

namespace Util {
	int random(const int, const int);
	void print(const char*);
	void print(const char*, int&);
	bool str_contains_letter(const std::string&, const char&);
}