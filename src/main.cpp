#include <fmt/color.h>
#include "hash/hasher.hpp"
#include <iostream>

int main()
{
    try
    {
        auto a = hasher::Basic();
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a.print();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}