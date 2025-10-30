#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float X, const float Y);
    Point(Point& other);
    Point& operator=(const Point& other);
    ~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif