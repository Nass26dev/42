#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int grade_s, int grade_e) : _name(name), _sign(false), _grade_s(grade_s), _grade_e(grade_e) {
    if (grade_s > 150 || grade_e > 150)
        GradeTooHighException();
    if (grade_s < 1 || grade_e < 1)
        GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

void Form::GradeTooHighException() const {
    throw std::runtime_error("Grade is too High");
}

void Form::GradeTooLowException() const {
    throw std::runtime_error("Grade is too Low");
}

void Form::beSigned(Bureaucrat &b) {
    int temp = b.getGrade();

    if (temp > 150)
        GradeTooHighException();
    if (temp < 1)
        GradeTooLowException();
    if (temp <= _grade_s)
        _sign = true;
    else
        GradeTooLowException();
}

std::string Form::getName() const {
    return (_name);
}

bool Form::getSign() const {
    return (_sign);
}

int Form::getGradeS() const {
    return (_grade_s);
}

int Form::getGradeE() const {
    return (_grade_e);
}

std::ostream& operator<<(std::ostream& out, Form &fo) {
    out << std::boolalpha << "name : " << fo.getName() << ", sign : " << fo.getSign() << ", grade to sign : " << fo.getGradeS() << ", grade to execute : " << fo.getGradeE();
    return out;
}