#include "../include/phoneBook.hpp"

Contact promptNewContact() {
    Contact c;
    promptFirstName(c);
    promptLastName(c);
    promptNickName(c);
    promptNumber(c);
    promptDarkestSecret(c);
    return (c);
}

void manageAdd(PhoneBook& pb) {
    Contact c = promptNewContact();
    pb.addContact(c);
    std::cout << "contact added successfully" << std::endl;
}

void manageSearch(PhoneBook& pb) {
	pb.displayContacts();
	int index = pb.getIndex();
	pb.displayContactDetails(index);
}

bool phonebook() {
    PhoneBook pb;
    std::string cmd;
 
    while (1) {
        std::cout << "enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd)) return(true);

        if (cmd == "ADD")
            manageAdd(pb);
        else if (cmd == "SEARCH")
            manageSearch(pb);
        else if(cmd == "EXIT")
            break ;
    }
	return (0);
}

int main() {
    if (phonebook()) return (1);
    std::cout << "Bye !" << std::endl;
    return(0);
}
