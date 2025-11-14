#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form {
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
    public :
        Form();
        Form(const std::string name, const int grade_sign, const int grade_execute);
        Form(const Form& other);

        ~Form();

        const std::string& getName() const;
        bool getIsSigned() const;
        const int getGradeToSign() const;
        const int getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif