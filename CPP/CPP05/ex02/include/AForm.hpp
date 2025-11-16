#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    protected:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
    public :
        AForm();
        AForm(const std::string& name, int grade_sign, int grade_execute);
        AForm(const AForm& other);

        AForm& operator=(const AForm& other);

        virtual ~AForm();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        virtual void beSigned(const Bureaucrat& b) = 0;
        virtual void execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class OpeningFileException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class FormUnsignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
