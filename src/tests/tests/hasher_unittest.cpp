#include "hash/hasher.hpp"

#include <gtest/gtest.h>

namespace hasher {
TEST(HasherLibrary, TestString) {
  const auto a = implmap::hash("Hello, world!");
  const auto b = implmap::hash("Hello, world!");
  EXPECT_EQ(a, b);
}

TEST(HasherLibrary, TestFloat) {
  const auto a = implmap::hash(1.3f);
  const auto b = implmap::hash(1.3f);
  EXPECT_EQ(a, b);
}
}  // namespace hasher