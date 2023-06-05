#include <fmt/color.h>

int main()
{
    fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold,
               "Hello, {}!\n", "world");
}