#include "hash/hasher.hpp"
#include <fmt/color.h>
#include <iostream>
#include "hasher.hpp"

using namespace hasher;

Copilot::Copilot()
{
    size = 0;
    capacity = 10;
    keys = new int[capacity];
    values = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        keys[i] = -1;
        values[i] = -1;
    }
}
Copilot::~Copilot()
{
    delete[] keys;
    delete[] values;
}

void Copilot::remove(int key)
{
    int index = hash(key);
    while (keys[index] != key)
    {
        index = (index + 1) % capacity;
    }
    keys[index] = -1;
    values[index] = -1;
    size--;
}

void Copilot::insert(int key, int value)
{
    if (size == capacity)
    {
        resize();
    }
    int index = hash(key);
    while (keys[index] != -1)
    {
        index = (index + 1) % capacity;
    }
    keys[index] = key;
    values[index] = value;
    size++;
}

int Copilot::get(int key)
{
    int index = hash(key);
    while (keys[index] != key)
    {
        index = (index + 1) % capacity;
    }
    return values[index];
}

void Copilot::print()
{
    for (int i = 0; i < capacity; i++)
    {
        if (keys[i] != -1)
        {
            std::cout << keys[i] << " " << values[i] << std::endl;
        }
    }
}

int Copilot::hash(int key)
{
    return key % capacity;
}

void Copilot::resize()
{
    int *oldKeys = keys;
    int *oldValues = values;
    int oldCapacity = capacity;
    capacity *= 2;
    keys = new int[capacity];
    values = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        keys[i] = -1;
        values[i] = -1;
    }
    for (int i = 0; i < oldCapacity; i++)
    {
        if (oldKeys[i] != -1)
        {
            insert(oldKeys[i], oldValues[i]);
        }
    }
    delete[] oldKeys;
    delete[] oldValues;
}

hasher::HashTable::HashTable()
{
}

hasher::HashTable::~HashTable()
{
}
