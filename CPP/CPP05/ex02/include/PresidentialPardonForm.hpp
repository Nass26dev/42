#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    void beSigned(Bureaucrat &b) override;
    void execute(Bureaucrat const &executor) const override; //TODO
};

#endif