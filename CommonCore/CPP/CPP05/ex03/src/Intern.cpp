#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string name, const std::string target) {
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = -1;

    while (++i < 3) {
        if (forms[i] == name) {
            break ;
        }
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates ShrubberyCreation" << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;    
        return new PresidentialPardonForm(target);
    default:
        std::cerr << "Intern can't creates " << name << std::endl;
        break;
    }
    return NULL;
}
