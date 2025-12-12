#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(const std::string& Name);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif