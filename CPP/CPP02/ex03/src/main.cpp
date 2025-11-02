#include "../include/Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);
    Point outside(10, 10);
    Point edge(0, 5);

    std::cout << std::boolalpha;
    std::cout << "Inside:  " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Edge:    " << bsp(a, b, c, edge) << std::endl;
}