#include "../include/contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

void Contact::setFirstName(const std::string& fn) { _firstName = fn; }
void Contact::setLastName(const std::string& ln) { _lastName = ln; }
void Contact::setNickname(const std::string& nn) { _nickname = nn; }
void Contact::setPhoneNumber(const std::string& pn) { _phoneNumber = pn; }
void Contact::setDarkestSecret(const std::string& ds) { _darkestSecret = ds; }

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::isEmpty() const {
    return (_firstName.empty());
}