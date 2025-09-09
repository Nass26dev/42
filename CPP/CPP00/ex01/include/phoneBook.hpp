#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook {
	private:
		Contact _contacts[8];
		int _nbContacts;
		int _oldestId;
	public:
		PhoneBook();
		void addContact(const Contact& c);
		void displayContacts() const;
		void displayContactDetails(int index) const;
		int getNbContacts() const;
		bool isValidIndex(int index) const;
		int getIndex() const;
};

void promptFirstName(Contact& c);
void promptLastName(Contact& c);
void promptNickName(Contact& c);
void promptNumber(Contact& c);
void promptDarkestSecret(Contact& c);

#endif
