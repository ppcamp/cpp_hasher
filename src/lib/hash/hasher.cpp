#include "hash/hasher.hpp"
#include <fmt/color.h>
#include <iostream>
#include "hasher.hpp"

hasher::Basic::Basic()
{
}

hasher::Basic::~Basic()
{
}

void hasher::Basic::print()
{
    // See https://hackingcpp.com/cpp/libs/fmt.html
    fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "{: ^30}", "Data\n");
    fmt::println("");
    for (int i = 0; i < 10; i++)
    {
        fmt::println("{: ^30}", m_element[i]);
    }
    fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "{: ^30}", "End Data\n");
    fmt::println("");
}

unsigned long hasher::Basic::hash_function(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % CAPACITY;
}