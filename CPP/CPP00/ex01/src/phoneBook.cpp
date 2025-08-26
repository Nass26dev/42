/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:56:20 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/29 17:48:10 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : nbContacts(0), oldestIndex(0) {}

void printColumn(const std::string &str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

void PhoneBook::addContact(const Contact& c) {
    contacts[oldestIndex] = c;
    if (nbContacts < 8) nbContacts++;
    oldestIndex = (oldestIndex + 1) % 8;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME" << "|"
              << std::setw(10) << "NICKNAME" << std::endl;

    for (int i = 0; i < nbContacts; ++i) {
        std::cout << std::setw(10) << i << "|";
        printColumn(contacts[i].getFirstName());
        std::cout << "|";
        printColumn(contacts[i].getLastName());
        std::cout << "|";
        printColumn(contacts[i].getNickname());
        std::cout << std::endl;
    }
}

void PhoneBook::displayContactDetail(int index) const {
    if (!isValidIndex(index)) {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    const Contact& c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

int PhoneBook::getNbContacts() const { return nbContacts; }

bool PhoneBook::isValidIndex(int index) const {
    return (index >= 0 && index < nbContacts);
}
