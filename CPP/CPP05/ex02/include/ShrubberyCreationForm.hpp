#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& name);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        ~ShrubberyCreationForm();

        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
};

#endif
