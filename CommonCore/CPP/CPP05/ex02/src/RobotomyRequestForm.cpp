#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 25, 5) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, 25, 5) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), 25, 5) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        _is_signed = other.getIsSigned();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _grade_to_sign) {
        throw AForm::GradeTooLowException();
    }
    _is_signed = true;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (_is_signed == false) {
        throw AForm::FormUnsignedException();
    }
    if (executor.getGrade() > _grade_to_execute) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Bzzzzz.... vrrrRRRRRrrrr... 🤖" << std::endl;

    srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << executor.getName() << " has been robotomized successfully !" << std::endl;
    }
    else {
        std::cout << "Robotomy failed for " << executor.getName() << " ..." << std::endl;
    }
}
