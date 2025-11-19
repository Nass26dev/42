#include "Base.hpp"
#include "ctime"
#include "cstdlib"

Base *generate(void) {
    srand(time(NULL));
    int id = rand() % 3;

    switch (id)
    {
    case 0:
        return new A;
        break;
    case 1:
        return new B;
        break;
    case 2:
        return new C;
        break;
    default:
        break;
    }
    return NULL;
}
