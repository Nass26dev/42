#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& to_cpy) {
    _value = to_cpy._value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb) {
    std::cout << "Int constructor called" << std::endl;
    _value = nb << _bits;
}

Fixed::Fixed(const float nb) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(nb * (1 << _bits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void  Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _bits);
}

int Fixed::toInt(void) const {
    return _value >> _bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}