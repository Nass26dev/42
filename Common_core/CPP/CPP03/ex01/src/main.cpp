#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Alpha");
    ScavTrap scav("Bravo");

    clap.attack("Training Dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("Enemy");
    clap.takeDamage(20);
    clap.beRepaired(10);

    scav.attack("Training Dummy");
    scav.takeDamage(40);
    scav.beRepaired(20);
    scav.guardGate();

    for (int i = 0; i < 55; ++i)
        scav.attack("Dummy");
    scav.guardGate();

    return 0;
}
