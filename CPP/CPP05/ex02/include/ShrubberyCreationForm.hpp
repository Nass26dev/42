#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    void beSigned(Bureaucrat &b) override;
    void execute(Bureaucrat const &executor) const override; //TODO

};

#endif