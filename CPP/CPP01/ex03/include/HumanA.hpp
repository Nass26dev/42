#ifndef HUMANA_HPP
#define HUMANA_HPP

#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private :
    Weapon& weapon;
    std::string name;
public :
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif