#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        
        Intern& operator=(const Intern& other);

        ~Intern();

        AForm* makeForm(const std::string name, const std::string target);
};

#endif