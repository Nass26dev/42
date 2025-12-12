#include "../include/Point.hpp"

static Fixed cross(Point const& p1, Point const& p2, Point const& p3) {
    return (p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y())
         - (p1.get_y() - p3.get_y()) * (p2.get_x() - p3.get_x());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1 = cross(point, a, b);
    Fixed d2 = cross(point, b, c);
    Fixed d3 = cross(point, c, a);

    if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
        return true;

    return false;
}