#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& Name) : ClapTrap(Name) {
    _Hit_Points = 100;
    _Energy_points = 50;
    _Attack_Damage = 20;
    std::cout << "ScavTrap: " << Name << " has been created" << std::endl;

}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: " << _Name << " Has been destroyed" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << _Name << " is now in Gate keeper mode." << std::endl;
}
