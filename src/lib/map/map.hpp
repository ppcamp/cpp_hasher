#pragma once

#ifndef HASHER_MACROS
#define HASHER_MACROS true
#define BucketCntBits 3
#define BucketCnt (1 << BucketCntBits)
#define LoadFactorNum 13
#define LoadFactorDen 2
#endif

#include "hash/hasher.hpp"

namespace implmap {
template <typename KeyType, typename ValueType>
class Basic {
 public:
  Basic() {}
  ~Basic() {}
  void insert(int key, int value) {}
  void remove(int key) {}

  ValueType get(KeyType key) {
    ValueType value;
    return value;
  }

  // int &operator=(int rhs)
  // {
  //     return m_element[rhs];
  // }
  // int &operator[](const int key)
  // {
  //     return get(key);
  // }

  void print() {}

 private:
  /// @brief Current number of keys in the hash table
  int m_size;

  /// @brief Current capacity of the hash table (number of buckets/positions
  /// available)
  int m_capacity;

  int *m_keys;
  int *m_values;
  int hash(KeyType key) {
    // return key % m_capacity;
    return implmap::hash(key) % m_capacity;
  }

  void resize() {}
  /// @brief Checks if the hash table should be resized
  /// @see https://en.wikipedia.org/wiki/Hash_table#Load_factor
  /// @return
  bool should_resize() { return true; }
};
}  // namespace implmap
