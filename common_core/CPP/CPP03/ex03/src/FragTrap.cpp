#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& Name) : ClapTrap(Name) {
    _Hit_Points = 100;
    _Energy_points = 100;
    _Attack_Damage = 30;
    std::cout << "FragTrap: " << Name << " has been created" << std::endl;

}

FragTrap::~FragTrap() {
        std::cout << "FragTrap: " << _Name << " Has been destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "Hey man , can I have a high five please ?" << std::endl;
}