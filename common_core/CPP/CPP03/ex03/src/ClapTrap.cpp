#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& Name) : _Name(Name), _Hit_Points(10), _Energy_points(10), _Attack_Damage(0) {
    std::cout << "ClapTrap: " << Name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap: " << _Name << " Has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_Energy_points > 0) {
        std::cout << "ClapTrap " << _Name << " attacks " << target << " causing " << _Attack_Damage << " points of damage!" << std::endl;
        _Energy_points--;
    }
    else
        std::cout << "No more energy points !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_Hit_Points > 0)
        _Hit_Points -= amount;
    else
        std::cout << _Name << " is already dead !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_Energy_points > 0) {
        _Hit_Points += amount;
        _Energy_points--;
    }
    else
        std::cout << "No more energy points !" << std::endl;
}
