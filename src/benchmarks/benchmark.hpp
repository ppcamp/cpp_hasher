#pragma once

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <unistd.h>

#include <chrono>

using namespace std::literals::chrono_literals;

template <typename F>
void bench(std::string name, F cb) {
  auto start = std::chrono::steady_clock::now();
  cb();
  auto end = std::chrono::steady_clock::now();

  // auto out = end - start;
  // This is the old way of doing it (without fmt):
  auto out = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                 .count();
  fmt::print(fmt::emphasis::bold | fg(fmt::color::green), "- {}: ", name);
  fmt::print("{}µs\n", out);
}