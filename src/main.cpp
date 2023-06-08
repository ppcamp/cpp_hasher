#include <fmt/color.h>
#include "hash/hasher.hpp"
#include <iostream>
#include <map>

int main()
{
    try
    {
        auto a = hasher::Copilot();
        a.insert(1, 0);
        a.insert(2, 3);
        a.print();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}