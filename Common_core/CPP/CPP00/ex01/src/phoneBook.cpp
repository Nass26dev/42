#include "../include/phoneBook.hpp"

PhoneBook::PhoneBook() : _nbContacts(0), _oldestId(0) {}

void printColumn(const std::string &str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

void PhoneBook::addContact(const Contact& c) {
	_contacts[_oldestId] = c;
	if (_nbContacts < 8) _nbContacts++;
	_oldestId = (_oldestId + 1) % 8;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME" << "|"
              << std::setw(10) << "NICKNAME" << std::endl;

    for (int i = 0; i < _nbContacts; ++i) {
        std::cout << std::setw(10) << i << "|";
        printColumn(_contacts[i].getFirstName());
        std::cout << "|";
        printColumn(_contacts[i].getLastName());
        std::cout << "|";
        printColumn(_contacts[i].getNickname());
        std::cout << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const {
    if (!isValidIndex(index)) {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    const Contact& c = _contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

int PhoneBook::getNbContacts() const { return (_nbContacts); }

bool PhoneBook::isValidIndex(int index) const {
    return (index >= 0 && index < _nbContacts);
}


int PhoneBook::getIndex() const {
	std::string strId;
	int index;

	while (true) {
		std::cout << "Enter contact index (0-" << (_nbContacts - 1) << "): ";
		
		if (!std::getline(std::cin, strId)) {
			std::cout << std::endl << "Input error" << std::endl;
			return -1;
		}
		if (strId.empty()) {
			std::cout << "Error: Empty input. Please try again." << std::endl;
			continue;
		}
		if (strId.length() != 1 || !std::isdigit(strId[0])) {
			std::cout << "Error: Invalid input. Please enter a single digit." << std::endl;
			continue;
		}
		index = strId[0] - '0';
		if (index < 0 || index > 7) {
			std::cout << "Error: Index out of range. Please enter a number between 0 and 7." << std::endl;
			continue;
		}
		if (index >= _nbContacts) {
			std::cout << "Error: No contact at index " << index << ". Available contacts: 0-" << (_nbContacts - 1) << std::endl;
			continue;
		}
		
		return index;
	}
}
