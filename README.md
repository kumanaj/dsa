# Data Structures in C++

C++17 data structure implementations for interview practice, tested with GoogleTest and built with CMake.

## Structures

| Data structure | Header | Key operations | Tests |
|---|---|---|---|
| Singly linked list | [singly_linked_list.hpp](./src/data_structures/singly_linked_list.hpp) | push/pop front/back, get, front, back, clear | ✅ |
| Doubly linked list | [doubly_linked_list.hpp](./src/data_structures/doubly_linked_list.hpp) | push/pop front/back (sentinel node) | ✅ |
| Dynamic array | [dynamic_array.hpp](./src/data_structures/dynamic_array.hpp) | insert_at, remove_at, push/pop, resize | 🚧 resize, push_back, front, back, clear to do |
| Binary search tree | [bst.hpp](./src/data_structures/bst.hpp) | insert, remove, search, min/max, height | ✅ |
| Graph (adjacency list) | [graph.hpp](./src/data_structures/graph.hpp) | add/remove vertex & edge, DFS, BFS, shortest path | 🚧 shortest_path to do |

## Layout

```
src/data_structures/   data structures, one header each
src/algorithms/        algorithms
src/problems/          interview problems
tests/                         same layout as src/, files named test_<name>.cpp
```

## Build & run tests

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DENABLE_ASAN=OFF
cmake --build build
ctest --test-dir build --output-on-failure
```

To enable AddressSanitizer, set `ENABLE_ASAN=ON`. New `test_*.cpp` files are picked up automatically after re-running the configure step.

## Requirements

- CMake ≥ 3.14
- C++17 compiler (GCC 9+, Clang 10+)
- GoogleTest is fetched automatically.
