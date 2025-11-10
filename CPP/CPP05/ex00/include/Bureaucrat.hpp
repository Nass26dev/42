#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void GradeTooHighException() const;
    void GradeTooLowException() const;
    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat &bu);

#endif