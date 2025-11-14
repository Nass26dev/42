#include "Form.hpp"

Form::Form() : _name("Default Form"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_sign), _grade_to_execute(grade_execute) {
    if (grade_sign < 1 || grade_execute < 1) {
        throw Form::GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other) : _name(other.getName()), _is_signed(false), _grade_to_sign(other.getGradeToSign()), _grade_to_execute(other.getGradeToExecute()) {
    
}
