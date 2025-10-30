#include "../include/Point.hpp"

Point::Point() : _y(0), _x(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _y(other._y), _x(other._x) {}

Point& Point::operator=(const Point& other) {
    if (this != &other)
    {
        _x = other.getx();
        _y = other.gety();
    }
}