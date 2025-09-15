#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie() : name("") {};
    ~Zombie();
    void announce(void) const;
    void setName(const std::string& name);
};

// newZombie.cpp
Zombie* zombieHorde(int N, std::string name);

#endif
