#include <iostream>
#include <math.h>

#include "Main.h"


int lives;

const std::string WORLD_POOL[3] = {
	"dfgdf",
	"sdgfsdfg",
	"sdfg"
};

bool Hangman::str_contains_letter(const std::string& string, const char& letter) {
	return string.find(letter) != std::string::npos;
}

void Hangman::print(const char* message) {
	std::cout << message << std::endl;
}

void Hangman::start() {
	Hangman::print("Starting Hangman! Picking word...");

	std::cin.get();
}

int main() {
	Hangman::print("Welcome to Hangman! Press 1 to start and 2 to quit.");

	int input;
	std::cin >> input;

	if (input == 1) {
		Hangman::start();
	}
	else {
		return EXIT_SUCCESS;
	}
}