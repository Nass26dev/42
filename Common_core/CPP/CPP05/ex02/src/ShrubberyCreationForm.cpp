#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 25, 5) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, 25, 5) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), 25, 5) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        _is_signed = other.getIsSigned();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _grade_to_sign) {
        throw AForm::GradeTooLowException();
    }
    _is_signed = true;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (_is_signed == false) {
        throw AForm::FormUnsignedException();
    }    
    if (executor.getGrade() > _grade_to_execute) {
        throw AForm::GradeTooLowException();
    }
    std::string filename = executor.getName() + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile) {
        throw AForm::OpeningFileException();
    }

    const char *tree = "       _-_       \n"
"    /~~   ~~\\    \n"
" /~~         ~~\\  \n"
"{               }\n"
" \\  _-     -_  /  \n"
"   ~  \\\\ //  ~    \n"
"_- -   | | _- _   \n"
"  _ -  | |   -_   \n"
"      /   \\       \n";

    outfile << tree << std::endl;
    outfile << tree << std::endl;
    outfile << tree << std::endl;

    outfile.close();
}
