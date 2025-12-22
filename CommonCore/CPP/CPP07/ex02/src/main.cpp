#include "Array.hpp"
#include <iostream>
#include <exception>

int main() {
    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 2;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << "\n\n";

    try {
        std::cout << a[10] << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception catched : index is out of range" << std::endl;
    }
    std::cout << std::endl;

    Array<int> b(a);

    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl << std::endl;

    Array<int> c;
    c = a;

    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << "\n\n";

    Array<std::string> s(3);
    s[0] = "Test";
    s[1] = "Arrayyy";
    s[2] = "yyyarrA";

    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << "\n\n";

    const Array<std::string> sc(s);

    std::cout << sc[0] << " " << sc[1] << " " << sc[2] << std::endl;

    try {
        std::cout << sc[5] << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception catched : index is out of range" << std::endl;
    }

    return 0;
}