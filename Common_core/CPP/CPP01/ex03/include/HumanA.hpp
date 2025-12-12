#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private :
    std::string name;
    Weapon& weapon;
public :
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif