#include <fmt/color.h>

#include <iostream>
#include <map>

int main() {
  try {
    std::cout << "Hello, World!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}