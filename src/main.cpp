#include <fmt/color.h>

#include <iostream>

int main() {
  try {
    std::cout << "Hello, World!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}