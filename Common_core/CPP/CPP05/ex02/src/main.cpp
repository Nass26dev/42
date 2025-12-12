#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat bob("Bob", 1);
    Bureaucrat jim("Jim", 150);

    ShrubberyCreationForm shrub("ShrubTest");
    RobotomyRequestForm robo("RobotTest");
    PresidentialPardonForm pardon("PresidentialTest");

    std::cout << std::endl;

    bob.executeForm(shrub);

    std::cout << std::endl;

    jim.signForm(shrub);
    jim.signForm(robo);
    jim.signForm(pardon);

    std::cout << std::endl;

    bob.signForm(shrub);
    bob.signForm(robo);
    bob.signForm(pardon);

    std::cout << std::endl;

    jim.executeForm(shrub);
    jim.executeForm(robo);
    jim.executeForm(pardon);
    
    std::cout << std::endl;

    bob.executeForm(shrub);
    bob.executeForm(robo);
    bob.executeForm(pardon);

    return 0;
}
