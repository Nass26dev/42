#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

AForm::AForm(const std::string& name, int grade_sign, int grade_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_sign), _grade_to_execute(grade_execute) {
    if (grade_sign < 1 || grade_execute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : _name(other.getName()), _is_signed(other.getIsSigned()), _grade_to_sign(other.getGradeToSign()), _grade_to_execute(other.getGradeToExecute()) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _is_signed = other.getIsSigned();
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _is_signed;
}

int AForm::getGradeToSign() const {
    return _grade_to_sign;
}

int AForm::getGradeToExecute() const {
    return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _grade_to_sign) {
        throw AForm::GradeTooLowException();
    }
    _is_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {(void)executor;}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << " is signed : " << std::boolalpha << f.getIsSigned() << ", grade to sign / grade to execute : " << f.getGradeToSign() << " / " << f.getGradeToExecute();
    return os;
}

const char *AForm::GradeTooHighException::what() const throw() {return "Grade is too high !";}

const char *AForm::GradeTooLowException::what() const throw() {return "Grade is too low !";}

const char*AForm::OpeningFileException::what() const throw() {return "Error: impossible to open file";}

const char *AForm::FormUnsignedException::what() const throw() {return "Form is unsigned !";}
