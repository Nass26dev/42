#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& name);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        ~RobotomyRequestForm();

        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
};

#endif
