#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::cout << "=== Création des animaux ===" << std::endl;
    const Animal* animals[6];

    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();
    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();

    std::cout << "\n=== Test des sons ===" << std::endl;
    for (int i = 0; i < 6; i++)
        animals[i]->makeSound();

    std::cout << "\n=== Test de la copie profonde ===" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "I want fish");
    Cat copiedCat = originalCat;

    std::cout << "Original Cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;

    originalCat.getBrain()->setIdea(0, "I want milk");
    std::cout << "Original Cat idea 0 (modifié): " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat idea 0 (doit rester inchangé): " << copiedCat.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Suppression des animaux ===" << std::endl;
    for (int i = 0; i < 6; i++)
        delete animals[i];

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}
