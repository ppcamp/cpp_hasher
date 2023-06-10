#pragma once

#include <functional>

namespace implmap {
/// @brief Computes the hash of a value
/// @tparam T A type that can be hashed such as int, float, string, etc.
/// @param value The value to hash
/// @return Hash of the value
/// @todo Implement a hash function manually
template <typename T>
uint hash(const T value) {
  return std::hash<T>{}(value);
}
}  // namespace implmap