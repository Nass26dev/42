#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), 25, 5) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        _is_signed = other.getIsSigned();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _grade_to_sign) {
        throw AForm::GradeTooLowException();
    }
    _is_signed = true;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (_is_signed == false) {
        throw AForm::FormUnsignedException();
    }
    if (executor.getGrade() > _grade_to_execute) {
        throw AForm::GradeTooLowException();
    }
    std::cout << _name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
