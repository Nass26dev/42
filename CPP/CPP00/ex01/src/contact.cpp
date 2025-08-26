/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:29:16 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/29 17:48:22 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setFirstName(const std::string& fn) { firstName = fn; }
void Contact::setLastName(const std::string& ln) { lastName = ln; }
void Contact::setNickname(const std::string& nn) { nickname = nn; }
void Contact::setPhoneNumber(const std::string& pn) { phoneNumber = pn; }
void Contact::setDarkestSecret(const std::string& ds) { darkestSecret = ds; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

bool Contact::isEmpty() const {
    return (firstName.empty());
}
