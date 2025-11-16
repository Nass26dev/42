#include "../include/Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
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

const char *Bureaucrat::GradeTooLowException::what() const throw() {return "Bureaucrat grade is too low !";}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException& e) {
        std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException& e) {
        std::cerr << _name << " can't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    catch (AForm::OpeningFileException& e) {
        std::cerr << _name << " can't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    catch (AForm::FormUnsignedException& e) {
        std::cerr << _name << " can't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
