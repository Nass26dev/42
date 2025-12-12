#include "Span.hpp"
#include <iostream>

int main() {
    try {
        Span sp1(5);

        sp1.addNumber(5);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);

        sp1.shortestSpan();
        sp1.longestSpan();

        std::cout << std::endl;
        Span sp2(10001);
        sp2.addMultipleNumbers(10000);

        sp2.shortestSpan();
        sp2.longestSpan();

        std::cout << std::endl;
        Span sp3(2);
        sp3.addNumber(10);

        sp3.shortestSpan();

    } catch (Span::IndexIsOutOfRange &e) {
        std::cerr << "IndexIsOutOfRange: " << e.what() << std::endl;
    } catch (Span::NoSpanFounded &e) {
        std::cerr << "NoSpanFounded: " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
