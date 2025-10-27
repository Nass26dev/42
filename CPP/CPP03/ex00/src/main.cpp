#include "ClapTrap.hpp"

int main() {
    ClapTrap c1("Alpha");

    c1.attack("Target1");
    c1.takeDamage(3);
    c1.beRepaired(5);

    for (int i = 0; i < 11; i++) {
        c1.attack("Dummy");
    }
    
    c1.takeDamage(100);
    c1.takeDamage(1);
    c1.beRepaired(10);

    return 0;
}
