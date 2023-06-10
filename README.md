# cpp hasher


This is a case of study to check it out the benefits/tradeoffs for maps implementation.

> A simple example of how to implement a hash function/algorithm.

## Introduction

In C++, we have `unordered_map`, which implements a hashtable and we also have `map`,
which implements a `red black tree`¹. In
[Go, we also have a builtin "unordered map" implementation](https://go.dev/src/runtime/map.go)

### In `C++`:

Stage|map|unordered_map
-----|---|----------
Ordering| increasing order of keys(by default) | no ordering
Implementation  | Self balancing BST  | Hash Table
||(like Red-Black Tree)
search time  | log(n)| O(1) -> Average
||| O(n) -> Worst Case
Insertion time  | log(n) + Rebalance  | Same as search
Deletion time| log(n) + Rebalance  | Same as search

See [here](https://www.geeksforgeeks.org/map-vs-unordered_map-c/) for this table ref.

> Remember that for every new Map type (such as map<int,int>, map<string,int>) we create a definition
> for it, and thus, increase the binary size.

### In Golang:

The "hashmap" algorithm has some heuristics embeded in, therefore, the only problem
with the Go implementation is the "resize" factor, which may occurr too often if you don't known
the capacity at building time (a determinant factor to use `unordered_map` in C++).


### Rust:

However, the Rust team uses a different algorithm, now called as
"[SwissTable](https://abseil.io/blog/20180927-swisstables)". This same algorithm can be found
by the C++ [abseil lib](https://abseil.io/docs/cpp/).


Note¹: See `/usr/include/c++/11/bits/stl_map.h`


### Result:

```bash
Benchmarks:

- bench insertion using my map: 24µs
- bench insertion using Cpp map: 3µs
- bench insertion using Cpp unordered map: 3µs
```

### See

- https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
- https://medium.com/kalamsilicon/hash-tables-implementation-in-go-48c165c54553
- https://www.youtube.com/watch?v=Tl7mi9QmLns&ab_channel=GopherAcademy
- https://abseil.io/blog/20180927-swisstables
- https://www.youtube.com/watch?v=ncHmEUmJZf4&ab_channel=CppCon
- https://stackoverflow.com/a/3341737
- https://datastructures.maximal.io/hash-tables/
- http://google.github.io/googletest/reference/assertions.html

## Dependecies

This repo also [vcpkg](https://github.com/microsoft/vcpkg#using-vcpkg-with-cmake)
to manage dependencies. All building process is done by using `Cmake`.
For unit tests, this repo uses the
[Google test suite](http://google.github.io/googletest/quickstart-cmake.html)


```bash
# Installing Cmake deps (to work in multi platform)
sudo apt install cmake pkg-config

# Installing the debugger:
sudo apt install gdb

# Installing vcpkg dependencies (packages dependecies)
cd vcpkg && vcpkg install #-x-install-root=..
```

See [here](https://learn.microsoft.com/pt-br/vcpkg/users/versioning#version-schemes) for more infos
about the `vcpkg` (package manager). [Here](https://vcpkg.io/en/packages.html) to search for pkgs.