/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:41:02 by nyousfi           #+#    #+#             */
/*   Updated: 2025/08/05 13:05:18 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

Contact promptNewContact() {
    Contact c;
    std::string input;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    c.setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    c.setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    c.setNickname(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    c.setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    c.setDarkestSecret(input);

    return (c);
}

int main() {
    PhoneBook pb;
    std::string cmd;

    while (1) {
        std::cout << "Entrez une commande (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd)) break;

        if (cmd == "ADD") {
            Contact c = promptNewContact();
            pb.addContact(c);
            std::cout << "Contact ajouté." << std::endl;
        }
        else if (cmd == "SEARCH") {
            pb.displayContacts();
            std::cout << "Index du contact à afficher: ";
            std::string indexStr;
            std::getline(std::cin, indexStr);
            std::stringstream ss(indexStr);
            int idx;
            if (!(ss >> idx) || !pb.isValidIndex(idx)) {
                std::cout << "Invalid index !" << std::endl;
            } else {
                pb.displayContactDetail(idx);
            }
        }
        else if (cmd == "EXIT") {
            break;
        }
    }
    std::cout << "Bye !" << std::endl;
    return (0);
}
