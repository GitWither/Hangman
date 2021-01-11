#include <iostream>
#include <fstream>
#include <math.h>

#include "Main.h"


int lives;

bool Hangman::str_contains_letter(const std::string& string, const char& letter) {
	return string.find(letter) != std::string::npos;
}

int Hangman::random(int min, int max) {
	return rand() % max;
}

void Hangman::print(const char* message) {
	std::cout << message << std::endl;
}

void Hangman::load_words(std::vector<std::string>& words) {
	std::fstream world_file_stream;

	world_file_stream.open("words.txt", std::ios::in);

	if (world_file_stream.is_open()) {
		std::string line;
		while (std::getline(world_file_stream, line)) {
			if (line[0] == '#') continue;
			words.push_back(line);
		}
		world_file_stream.close();
	}
	else Hangman::print("Unable to load words");
}

void Hangman::start() {
	std::vector<std::string> words;
	Hangman::load_words(words);
	Hangman::print("Starting Hangman! Picking word...");

	std::string selected_word = words[Hangman::random(0, words.size())];
	Hangman::print(selected_word.c_str());

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