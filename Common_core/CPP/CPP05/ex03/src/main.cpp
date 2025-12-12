#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat b("Bureaucrat", 1);
    Intern someRandomIntern;
    AForm *rrf, *scf, *ppf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    rrf->beSigned(b);
    scf->beSigned(b);
    ppf->beSigned(b);
    b.executeForm(*rrf);
    b.executeForm(*scf);
    b.executeForm(*ppf);

    delete rrf;
    delete scf;
    delete ppf;

    AForm *bad = someRandomIntern.makeForm("fokaofkazopf", "fazokfa");
    (void)bad;
    return 0;
}
