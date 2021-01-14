#pragma once

#include <string>
#include <vector>

namespace Hangman {
	void load_words(std::vector<std::string>&);
	void start();
	void main_loop(std::string&, std::string&);
	bool check_and_correct(const char&, std::string&, std::string&);
	std::string string_to_blank(const std::string&);
	std::string reveal_word(const std::string&, const std::string&, const char&);
}