#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
private:
    std::string _Name;
public:
    DiamondTrap(const std::string& Name);
    ~DiamondTrap();
    void attack(const std::string& target);
    void whoAmI();
};

#endif