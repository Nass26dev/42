#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;    
}

void PresidentialPardonForm::beSigned(Bureaucrat &b) {
    int temp = b.getGrade();

    if (temp > 150)
        GradeTooHighException();
    if (temp < 1)
        GradeTooLowException();
    if (temp <= getGradeS())
        setSign();
    else
        GradeTooLowException();
}
