#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& Name) : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name) {
    _Hit_Points = FragTrap::_Hit_Points;
    _Energy_points = ScavTrap::_Energy_points;
    _Attack_Damage = FragTrap::_Attack_Damage;
    std::cout << "DiamondTrap: " << Name << " has been created" << std::endl;
}

DiamondTrap::~DiamondTrap() {
        std::cout << "DiamondTrap: " << _Name << " Has been destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _Name 
              << ", ClapTrap name: " << ClapTrap::_Name << std::endl;
}