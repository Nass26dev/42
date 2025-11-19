#include "iter.hpp"

int square(int x) { return x * x; }

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, square);

    for (int i : arr) {
        std::cout << i << " ";
    }
}
