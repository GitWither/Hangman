#include <iostream>
#include <string>

int lives;

const std::string WORLD_POOL[3] = {
	"dfgdf",
	"sdgfsdfg",
	"sdfg"
};

bool str_contains_letter(const std::string& string, const char& letter) {
	return string.find(letter) != std::string::npos;
}


int main() {
	std::cout << str_contains_letter(WORLD_POOL[0], 'f') << std::endl;
}