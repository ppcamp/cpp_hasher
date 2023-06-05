#include "hash/hasher.hpp"
#include <fmt/color.h>
#include <iostream>

void hasher::print()
{
    try
    {
        fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold,
                   "Hello, {}!\n", "world");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
