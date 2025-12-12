#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Creating characters ===" << std::endl;
    ClapTrap clap("Alpha");
    ScavTrap scav("Bravo");
    FragTrap frag("Charlie");
    DiamondTrap diamond("Diamond");

    std::cout << "\n=== Testing ClapTrap ===" << std::endl;
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    scav.attack("Target2");
    scav.takeDamage(40);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    frag.attack("Target3");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();

    std::cout << "\n=== Testing DiamondTrap ===" << std::endl;
    diamond.attack("Boss");
    diamond.takeDamage(30);
    diamond.beRepaired(15);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();

    std::cout << "\n=== Testing DiamondTrap energy exhaustion ===" << std::endl;
    for (int i = 0; i < 60; ++i)
        diamond.attack("Dummy");

    std::cout << "\n=== End of test ===" << std::endl;
    return 0;
}
