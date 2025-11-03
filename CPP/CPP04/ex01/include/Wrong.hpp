#ifndef WRONG_HPP
#define WRONG_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    ~WrongAnimal();
    std::string getType() const;
    void makeSound() const;
};

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    ~WrongCat();
    void makeSound() const;
};

#endif