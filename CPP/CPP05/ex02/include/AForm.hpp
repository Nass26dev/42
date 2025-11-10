#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _sign;
	const int _grade_s;
	const int _grade_e;
public:
	AForm(std::string name, int grade_s, int grade_e);
	virtual ~AForm();
	void GradeTooHighException() const;
	void GradeTooLowException() const;
	std::string getName() const;
	bool getSign() const;
	int getGradeS() const;
	int getGradeE() const;
	void setSign();
	virtual void execute(Bureaucrat const &executor) = 0;
	virtual void beSigned(Bureaucrat &b) = 0;
};

std::ostream& operator<<(std::ostream& out, AForm &fo);

#endif