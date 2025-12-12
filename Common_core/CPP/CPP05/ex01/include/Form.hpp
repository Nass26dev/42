#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
    public :
        Form();
        Form(const std::string& name, int grade_sign, int grade_execute);
        Form(const Form& other);

        Form& operator=(const Form& other);

        virtual ~Form();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
