#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const Fixed& to_cpy) {
    _value = to_cpy._value;
}

Fixed::Fixed(const int nb) {
    _value = nb << _bits;
}

Fixed::Fixed(const float nb) {
    _value = roundf(nb * (1 << _bits));
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed New;

    New.setRawBits(this->getRawBits() + other.getRawBits());
    return (New);
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed New;

    New.setRawBits(this->getRawBits() - other.getRawBits());
    return (New);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed New;

    New.setRawBits((this->getRawBits() * other.getRawBits()) >> _bits);
    return (New);
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed New;

    New.setRawBits((this->getRawBits() << _bits) / other.getRawBits());
    return (New);
}

Fixed& Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _value--;
    return tmp;
}

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

int Fixed::getRawBits(void) const {
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

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    float fa = a.toFloat();
    float fb = b.toFloat();

    if (fa < fb)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    float fa = a.toFloat();
    float fb = b.toFloat();

    if (fa < fb)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    float fa = a.toFloat();
    float fb = b.toFloat();

    if (fa > fb)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    float fa = a.toFloat();
    float fb = b.toFloat();

    if (fa > fb)
        return (a);
    return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}