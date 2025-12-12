#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    AAnimal* animals[6];

    for (size_t i = 0; i < 3; i++) {
        std::cout << i << " : ";
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (size_t i = 3; i < 6; i++) {
        std::cout << i << " : ";
        animals[i] = new Cat();
        std::cout << std::endl;
    }
    
    for (size_t i = 0; i < 6; i++) {
        animals[i]->makeSound();
    }
    
    std::cout << std::endl << "Deep copy test :" << std::endl;

    Dog BasicDog;
    {
        Dog tmpDog = BasicDog;
    }
    Cat BasicCat;
    {
        Cat tmpCat = BasicCat;
    }

    std::cout << std::endl;

    for (size_t i = 0; i < 6; i++) {
        std::cout << i << " : ";
        delete animals[i];
        std::cout << std::endl;
    }

    {
        Dog D;
        Cat C;
        
        std::cout << std::endl;
        
        try {
            D.getBrain()->setIdea("I want milk", 0);
            C.getBrain()->setIdea("I want fish", 0);
            
            std::cout << "Dog idea: " << D.getBrain()->getIdea(0) << std::endl;
            std::cout << "Cat idea: " << C.getBrain()->getIdea(0) << std::endl;
        }
        catch (Brain::IndexIsTooHigh& e) {
            std::cerr << e.what() << std::endl;
            return (1);
        }
        catch (Brain::IndexIsTooLow& e) {
            std::cerr << e.what() << std::endl;
            return (1);
        }
    }

    std::cout << std::endl;

    try {
        Dog original;
        original.getBrain()->setIdea("Hello", 0);
        
        Dog copy = original;
        
        original.getBrain()->setIdea("New idea", 0);
        
        std::cout << "original[0]: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy[0]:     " << copy.getBrain()->getIdea(0) << std::endl;
    }
    catch (Brain::IndexIsTooHigh& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    catch (Brain::IndexIsTooLow& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return 0;
}
