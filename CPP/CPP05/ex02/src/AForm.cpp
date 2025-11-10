#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int grade_s, int grade_e) : _name(name), _sign(false), _grade_s(grade_s), _grade_e(grade_e) {
    if (grade_s > 150 || grade_e > 150)
        GradeTooHighException();
    if (grade_s < 1 || grade_e < 1)
        GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "Form destructor called" << std::endl;
}

void AForm::GradeTooHighException() const {
    throw std::runtime_error("Grade is too High");
}

void AForm::GradeTooLowException() const {
    throw std::runtime_error("Grade is too Low");
}

void AForm::beSigned(Bureaucrat &b) {
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

std::string AForm::getName() const {
    return (_name);
}

bool AForm::getSign() const {
    return (_sign);
}

int AForm::getGradeS() const {
    return (_grade_s);
}

int AForm::getGradeE() const {
    return (_grade_e);
}

void AForm::setSign() {
    _sign = true;
}

void execute(Bureaucrat const &executor) {
    (void)executor;
    return ;
}

std::ostream& operator<<(std::ostream& out, AForm &fo) {
    out << std::boolalpha << "name : " << fo.getName() << ", sign : " << fo.getSign() << ", grade to sign : " << fo.getGradeS() << ", grade to execute : " << fo.getGradeE();
    return out;
}