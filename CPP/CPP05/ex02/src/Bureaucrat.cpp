#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (grade > 150)
        GradeTooHighException();
    if (grade < 1)
        GradeTooLowException();
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::GradeTooHighException() const {
    throw std::runtime_error("Grade is too High");
}

void Bureaucrat::GradeTooLowException() const {
    throw std::runtime_error("Grade is too Low");
}

void Bureaucrat::incrementGrade() {
    _grade++;
    if (_grade > 150)
        GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    _grade--;
    if (_grade < 1)
        GradeTooLowException();
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
    }
    catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << _name << " signed " << f.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat &bu) {
    out << bu.getName() << ", bureaucrat grade " << bu.getGrade();
    return out;
}
