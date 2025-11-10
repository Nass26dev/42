#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;    
}

void RobotomyRequestForm::beSigned(Bureaucrat &b) {
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
