#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;    
}

void ShrubberyCreationForm::beSigned(Bureaucrat &b) {
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

