#include "Util.h"
#include <iostream>
#include <math.h>


bool Util::str_contains_letter(const std::string& string, const char& letter) {
	return string.find(letter) != std::string::npos;
}

int Util::random(const int min, const int max) {
	return rand() % (max - min) + min;
}

void Util::print(const char* input) {
	std::cout << input << std::endl;
}

void Util::print(const char* input, int& number) {
	std::cout << input << " " << number << std::endl;
}