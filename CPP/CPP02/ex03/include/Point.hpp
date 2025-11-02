#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    Fixed get_x() const;
    Fixed get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif