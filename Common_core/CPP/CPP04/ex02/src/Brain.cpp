#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain : Default constructor was called" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (size_t i = 0; i < 100; i++) {
        _ideas[i] = other.getIdea(i);
    }
    std::cout << "Brain : Copy constructor was called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; i++) {
            _ideas[i] = other.getIdea(i);
        }
    }
    std::cout << "Brain : Copy assignement was called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain : Destructor was called" << std::endl;
}

void Brain::setIdea(const std::string& idea, const int index) {
    if (index < 0)
        throw Brain::IndexIsTooLow();
    if (index > 100)
        throw Brain::IndexIsTooHigh();
    _ideas[index] = idea;
}

std::string Brain::getIdea(const int index) const {
    if (index < 0)
        throw Brain::IndexIsTooLow();
    if (index > 99)
        throw Brain::IndexIsTooHigh();
    return _ideas[index];
}

const char *Brain::IndexIsTooHigh::what() const throw() {
    return "Index is too high !";
}

const char *Brain::IndexIsTooLow::what() const throw() {
    return "Index is too low !";
}
