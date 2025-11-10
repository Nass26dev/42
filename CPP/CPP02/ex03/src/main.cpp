#include "../include/Point.hpp"

void testBSP(std::string const &testName, Point const &a, Point const &b, Point const &c, Point const &p, bool expected)
{
    bool result = bsp(a, b, c, p);
    std::cout << testName << " : ";
    if (result == expected)
        std::cout << "✅ [OK]";
    else
        std::cout << "❌ [KO]";
    std::cout << " → bsp(" << p << ") = " << std::boolalpha << result << std::endl;
}

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    std::cout << "Triangle vertices: A" << a << ", B" << b << ", C" << c << std::endl;

    Point p1(5.0f, 5.0f);
    testBSP("Test 1 - Inside", a, b, c, p1, true);

    Point p2(5.0f, 0.0f);
    testBSP("Test 2 - On edge (AB)", a, b, c, p2, false);

    Point p3(0.0f, 0.0f);
    testBSP("Test 3 - On vertex (A)", a, b, c, p3, false);

    Point p4(10.0f, 10.0f);
    testBSP("Test 4 - Outside", a, b, c, p4, false);

    Point p5(5.0f, -0.1f);
    testBSP("Test 5 - Near edge but outside", a, b, c, p5, false);

    Point p6(5.0f, 0.1f);
    testBSP("Test 6 - Near edge but inside", a, b, c, p6, true);

    Point d1(0.0f, 0.0f);
    Point d2(5.0f, 5.0f);
    Point d3(10.0f, 10.0f);
    Point p7(5.0f, 5.0f);
    testBSP("Test 7 - Degenerate triangle", d1, d2, d3, p7, false);

    Point e1(0.0f, 0.0f);
    Point e2(0.0f, 10.0f);
    Point e3(10.0f, 0.0f);
    Point p8(3.0f, 3.0f);
    testBSP("Test 8 - Reverse order triangle", e1, e2, e3, p8, true);

    return 0;
}
