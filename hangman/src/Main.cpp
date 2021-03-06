#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

#include "Main.h"
#include "Util.h"

constexpr int MAX_LIVES = 10;


int lives;

std::string Hangman::reveal_word(const std::string& word, const std::string& hidden_word, const char& character) {
	std::string output;
	//Iterate through all the characters in the word
	for (unsigned int i = 0; i < word.size(); i++) {
		//If current character is equal to the inputted character, add it to the output
		if (word[i] == character) {
			output += character + static_cast<std::string>(" ");
		}
		//Else, if the hidden word does not have an underscore or a space at the current index, add whatever it has to the output
		else if (hidden_word[i * 2] != '_' && hidden_word[i * 2] != ' ') {
			output += hidden_word[i * 2] + static_cast<std::string>(" ");
		}
		//Else, just add an underscore and a space to the output 
		else {
			output += "_ ";
		}
	}
	return output;
}

std::string Hangman::string_to_blank(const std::string& input) {
	std::string output;
	for (int i = 0; i < input.size(); i++) {
		output += "_ ";
	}
	return output;
}

bool Hangman::check_and_correct(const char& input, std::string& word, std::string& output) {
	if (Util::str_contains_letter(word, input)) {
		output = reveal_word(word, output, input);
		return true;
	}
	else {
		return false;
	}
}

void Hangman::load_words(std::vector<std::string>& words) {
	std::fstream world_file_stream;

	world_file_stream.open("words.txt", std::ios::in);

	if (world_file_stream.is_open()) {
		std::string line;
		while (std::getline(world_file_stream, line)) {
			if (line[0] == '#' || line.empty()) continue;
			words.push_back(line);
		}
		world_file_stream.close();
	}
	else Util::print("Unable to load words");
}

void Hangman::main_loop(std::string& selected_word, std::string& hidden_word) {
	Util::print("Type a letter and see if it's correct!");

	char input;
	std::cin >> input;

	//Check if player still has lives
	if (lives > 1) {
		//Check if word has been discovered yet
		if (Hangman::check_and_correct(input, selected_word, hidden_word)) {
			Util::print(hidden_word.c_str());
			if (!Util::str_contains_letter(hidden_word, '_')) {
				Util::print("You won!");
				std::exit(EXIT_SUCCESS);
			}
		}
		else {
			lives--;
			Util::print("The word does not contain that letter! Lives remaining:", lives);
		}
	}
	//If not, print you lost
	else {
		Util::print("You lost!");
		std::exit(EXIT_SUCCESS);
	}
	Hangman::main_loop(selected_word, hidden_word);
}

void Hangman::start() {
	std::vector<std::string> words;
	//words.push_back("Cat");
	Hangman::load_words(words);
	Util::print("Starting Hangman! Picking word...");

	std::srand(time(NULL));

	int random_index = Util::random(0, words.size());
	std::string selected_word = words[random_index];
	std::string hidden_word = Hangman::string_to_blank(selected_word);
	Util::print("Word selected!");
    Util::print(hidden_word.c_str());

	lives = MAX_LIVES;

	Hangman::main_loop(selected_word, hidden_word);
}

int main() {
	Util::print("Welcome to Hangman! Press 1 to start and 2 to quit.");

	int input;
	std::cin >> input;

	if (input == 1) {
		Hangman::start();
	}
	else {
		return EXIT_SUCCESS;
	}
}