#include "absl/container/flat_hash_map.h"
#include "benchmark.hpp"
#include "map"
#include "map/map.hpp"
#include "unordered_map"

void bench_insertions() {
  bench("bench insertion using my map", []() {
    implmap::Basic<std::string, int> map;
    map.insert("a", 1);
    map.insert("b", 2);
    map.insert("c", 3);
    map.insert("d", 4);
    map.insert("a", 5);
    map.insert("a", 6);
  });

  bench("bench insertion using Cpp map", []() {
    std::map<std::string, int> map;
    map["a"] = 1;
    map["b"] = 2;
    map["c"] = 3;
    map["d"] = 4;
    map["a"] = 5;
    map["a"] = 6;
  });

  bench("bench insertion using Cpp unordered map", []() {
    std::unordered_map<std::string, int> map;
    map["a"] = 1;
    map["b"] = 2;
    map["c"] = 3;
    map["d"] = 4;
    map["a"] = 5;
    map["a"] = 6;
  });

  // TODO: fix abseil linking
  //   bench("bench insertion using abseil map", []() {
  //     absl::flat_hash_map<std::string, int> map;
  //     map.insert({"a", 1});
  //     map.insert({"b", 2});
  //     map.insert({"c", 3});
  //     map.insert({"d", 4});
  //     map.insert({"a", 5});
  //     map.insert({"a", 6});
  //   });
}

int main() {
  fmt::print(fmt::emphasis::bold | fg(fmt::color::cyan), "Benchmarks:\n\n");
  bench_insertions();
}