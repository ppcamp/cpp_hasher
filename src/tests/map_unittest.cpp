#include "map/map.hpp"

#include <gtest/gtest.h>

#include <utility>

namespace hasher {
TEST(MapLibrary, TestInsertAndCheck) {
  implmap::Basic<std::string, int> map;
  map.insert("a", 1);
  map.insert("b", 2);
  map.insert("c", 3);
  map.insert("d", 4);
  map.insert("a", 5);
  map.insert("a", 6);

  auto tests = {std::make_pair("a", 6), std::make_pair("b", 2),
                std::make_pair("c", 3), std::make_pair("d", 4)};

  for (auto test : tests) {
    int* value = map.get(test.first);
    EXPECT_EQ(test.second, *value);
  }
}

TEST(MapLibrary, TestRemove) {
  implmap::Basic<std::string, int> map;
  map.insert("a", 1);
  map.insert("b", 2);
  map.insert("c", 3);
  map.insert("d", 4);
  map.insert("a", 5);
  map.insert("a", 6);

  map.remove("a");
  map.remove("b");
  map.remove("c");
  map.remove("d");

  for (auto test : {"a", "b", "c", "d"}) {
    int* value = map.get(test);
    EXPECT_EQ(nullptr, value);
  }
}
}  // namespace hasher