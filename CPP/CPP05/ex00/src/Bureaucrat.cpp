#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_cpy) : _name(to_cpy._name), _grade(to_cpy._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    _grade = other.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName() const {return _name;}

int Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::incrementGrade() {
    if ((_grade - 1) < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if ((_grade + 1) > 150)
        throw GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {return "Bureaucrat grade is too high !";}

const char *Bureaucrat::GradeTooLowException::what() const throw() {return "Bureacrat grade is too low !";}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
