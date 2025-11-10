#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _sign;
	const int _grade_s;
	const int _grade_e;
public:
	Form(std::string name, int grade_s, int grade_e);
	~Form();
	void GradeTooHighException() const;
	void GradeTooLowException() const;
	std::string getName() const;
	bool getSign() const;
	int getGradeS() const;
	int getGradeE() const;
	void beSigned(Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& out, Form &fo);

#endif