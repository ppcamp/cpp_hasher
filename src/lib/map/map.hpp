#pragma once

#ifndef HASHER_MACROS
#define HASHER_MACROS
#define BUCKET_N_MULTIPLIER 3
#define BUCKET_N (1 << BUCKET_N_MULTIPLIER)
#define HASHTABLE_CAPACITY_GROW_MULTIPLIER 1.5
#define HASHTABLE_DEFAULT_CAPACITY 100
#endif

#include <fmt/core.h>

#include <cstdint>
#include <iomanip>
#include <iostream>

#include "hash/hasher.hpp"

namespace implmap {

/// @brief Basic hash table implementation
/// @tparam KeyType Type of the key
/// @tparam ValueType Type of the value
/// @note This implmentation isn't thread-safe
/// @todo Reduce hashtable size when we pop an element
template <typename KeyType, typename ValueType>
class Basic {
 public:
  Basic() {
    m_capacity = HASHTABLE_DEFAULT_CAPACITY;
    m_size = 0;
    m_table = create_table(m_capacity);
  }

  ~Basic() {}

  ///@brief Remove the element with the given key
  ///@param key Key to search for
  ///@note If the key is not found, nothing happens
  ///@todo This function should reduce the size of the hashtable basing on the
  /// load factor (size/capacity)
  void remove(KeyType key) {
    const uint32_t pos = get_index(key);
    for (size_t p = 0; p < m_table[pos].size; p++) {
      if (m_table[pos].items[p].key == key) {
        // we found the key, so we need to remove it
        // we can do this by moving the last element to the position of the
        // element we want to remove
        m_table[pos].items[p] = m_table[pos].items[m_table[pos].size - 1];
        m_table[pos].size--;
        m_size--;
        return;
      }
    }
  }

  //   ValueType& operator=(KeyType key) {
  //     auto a = get(key);
  //     return a;
  //   }
  //   ValueType &operator[](const int key)
  //   {
  //     auto a = insertAt(m_table, key, 0);
  //       return get(key);
  //   }

  void insert(KeyType key, ValueType value) { insertAt(m_table, key, value); }

  /// @brief Get the current value associated with the given key
  /// @param key Key to search for
  /// @return Pointer to the value associated with the given key, or nullptr if
  /// the key is not found
  ValueType* get(KeyType key) {
    const uint32_t pos = get_index(key);
    const auto table = m_table[pos];
    for (size_t p = 0; p < table.size; p++) {
      if (table.items[p].key == key) {
        return &table.items[p].value;
      }
    }
    return nullptr;
  }

  void print() {
    for (int i = 0; i < m_capacity; i++) {
      const auto table = m_table[i];
      for (size_t p = 0; p < table.size; p++) {
        fmt::print("{:^10}", fmt::format("table({},{}) ", table.items[p].key,
                                         table.items[p].value));
      }
      if (table.size > 0) std::cout << std::endl;
    }
  }

  void erase() {
    for (int i = 0; i < m_capacity; i++) {
      delete[] m_table[i].items;
    }
    delete[] m_table;
  }

 private:
  struct BucketItem {
    KeyType key;
    ValueType value;
  };

  struct Bucket {
    /// @brief Number of items in the bucket
    uint32_t size;

    /// @brief Array of elements in the bucket (key-value pairs), where the key
    /// is the same.
    BucketItem* items;
  };

  /// @brief Insert a new key-value pair in the hash table
  /// @param key Key to insert
  /// @param value Value to insert
  /// @note If the key already exists, the value is updated
  /// @note If the number of elements in the bucket is equal to BUCKET_N, the
  /// hash table is resized
  /// @todo Implement a better way to handle collisions
  /// @todo Check what happens if we call a resize and inside of a resize we
  /// call another one?
  void insertAt(Bucket* htable, KeyType key, ValueType value) {
    const uint32_t pos = get_index(key);
    if (htable[pos].size == BUCKET_N) {
      // we reached the max number of elements in the bucket, thus, we have more
      // than BUCKET_N colisions, so we need to resize the hash htable[pos]
      resize();
    }

    // update if the key already exists
    for (size_t p = 0; p < htable[pos].size; p++) {
      if (htable[pos].items[p].key == key) {
        htable[pos].items[p].value = value;
        return;
      }
    }

    // insert the new key
    htable[pos].items[htable[pos].size] = {key, value};
    htable[pos].size++;
    m_size++;
  }

  /// @brief Create a new hash table with the given capacity
  void resize() {
    const uint32_t new_capacity =
        m_capacity * HASHTABLE_CAPACITY_GROW_MULTIPLIER;
    Bucket* new_table = create_table(new_capacity);

    // iterate over the old table and insert the elements in the new table
    for (size_t i = 0; i < m_capacity; i++) {
      const auto table = m_table[i];
      for (size_t p = 0; p < table.size; p++) {
        KeyType key = table.items[p].key;
        ValueType value = table.items[p].value;
        insertAt(new_table, key, value);
      }
    }

    // delete the old table
    erase();

    m_capacity = new_capacity;
    m_table = new_table;
  }

  /// @brief Create a new hash table
  /// @param cap Capacity of the new hash table
  /// @return Pointer to the new hash table
  Bucket* create_table(uint32_t cap) {
    Bucket* table = new Bucket[m_capacity];
    for (int i = 0; i < m_capacity; i++) {
      table[i].items = new BucketItem[BUCKET_N];
      table[i].size = 0;
    }
    return table;
  }

  /// @brief Get the index of the bucket where the given key should be stored
  /// @param key Key to search for the bucket
  /// @return Index of the bucket where the given key should be stored
  uint32_t get_index(KeyType key) {
    // return key % m_capacity;
    return implmap::hash(key) % m_capacity;
  }

  /// @brief Current number of keys in the hash table
  uint32_t m_size;

  /// @brief Current capacity of the hash table (number of buckets/positions
  /// available)
  uint32_t m_capacity;

  /// @brief Array of buckets
  Bucket* m_table;
};
}  // namespace implmap
