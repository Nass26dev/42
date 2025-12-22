#include "../include/phoneBook.hpp"

void promptFirstName(Contact& c) {
	std::string prompt;
	
	prompt = "";
	while (prompt == "") {
		std::cout << "First name : ";
		std::getline(std::cin, prompt);
	}
	c.setFirstName(prompt);
}
void promptLastName(Contact& c) {
	std::string prompt;
	
	prompt = "";
	while (prompt == "") {
		std::cout << "Last name : ";
		std::getline(std::cin, prompt);
	}
	c.setLastName(prompt);
}

void promptNickName(Contact& c) {
	std::string prompt;
	
	prompt = "";
	while (prompt == "") {
		std::cout << "Nickname : ";
		std::getline(std::cin, prompt);
	}
	c.setNickname(prompt);
}

void promptNumber(Contact& c) {
	std::string prompt;
	
	prompt = "";
	while (prompt == "") {
		std::cout << "Phone number : ";
		std::getline(std::cin, prompt);
	}
	c.setPhoneNumber(prompt);
}

void promptDarkestSecret(Contact& c) {
	std::string prompt;
	
	prompt = "";
	while (prompt == "") {
		std::cout << "Darkest secret : ";
		std::getline(std::cin, prompt);
	}
	c.setDarkestSecret(prompt);
}
