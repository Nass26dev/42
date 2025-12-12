#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(const std::string& name, int grade_sign, int grade_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_sign), _grade_to_execute(grade_execute) {
    if (grade_sign < 1 || grade_execute < 1) {
        throw Form::GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other) : _name(other.getName()), _is_signed(other.getIsSigned()), _grade_to_sign(other.getGradeToSign()), _grade_to_execute(other.getGradeToExecute()) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _is_signed = other.getIsSigned();
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _is_signed;
}

int Form::getGradeToSign() const {
    return _grade_to_sign;
}

int Form::getGradeToExecute() const {
    return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _grade_to_sign) {
        throw Form::GradeTooLowException();
    }
    _is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << " is signed : " << std::boolalpha << f.getIsSigned() << ", grade to sign / grade to execute : " << f.getGradeToSign() << " / " << f.getGradeToExecute();
    return os;
}

const char *Form::GradeTooHighException::what() const throw() {return "Grade is too high !";}

const char *Form::GradeTooLowException::what() const throw() {return "Grade is too low !";}
