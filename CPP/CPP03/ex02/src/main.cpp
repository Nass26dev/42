#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("Alpha");
    ScavTrap scav("Bravo");
    FragTrap frag("Charlie");

    clap.attack("Dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.attack("Target");
    scav.takeDamage(40);
    scav.beRepaired(20);
    scav.guardGate();

    frag.attack("BigBoss");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();

    for (int i = 0; i < 105; i++)
        frag.attack("Dummy");

    return 0;
}
