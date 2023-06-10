#pragma once

namespace implmap {
/// @brief A sum method that returns the sum of two numbers.
/// @note Since it is a template, it can be used with any type that supports the
/// + operator. Although, we can't split it into cpp files
/// @tparam T float/double/int/long/long long
/// @param a Some number
/// @param b Another number
/// @return The sum of a and b
template <class T>
T sum(T a, T b) {
  return a + b;
}
}  // namespace implmap
