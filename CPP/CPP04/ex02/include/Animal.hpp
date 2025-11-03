#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include <Brain.hpp>

class Animal {
protected:
    std::string _type;
public:
    Animal();
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;
    virtual Brain* getBrain() const = 0;
};

#endif