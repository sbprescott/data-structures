#include <iostream>
#include <string>
#include "vector.h"

int main()
{
    Vector v(10);
    std::cout << "Made a new vector.\n";
    std::cout << "Size: " + std::to_string(v.size()) + "\n";
    std::cout << "First element: " + std::to_string(v[0]) + "\n";
    v[0] = 1;
    std::cout << "Changed first element: " + std::to_string(v[0]) + "\n";
}