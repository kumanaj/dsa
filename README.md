# Data Structures in C++

C++17 data structure implementations for interview practice, tested with GoogleTest and built with CMake.

## Structures

| Data structure | Header | Key operations | Tests |
|---|---|---|---|
| Singly linked list | [singly_linked_list.hpp](./src/data_structures/singly_linked_list.hpp) | push/pop front/back, get, front, back, clear | ✅ |
| Doubly linked list | [doubly_linked_list.hpp](./src/data_structures/doubly_linked_list.hpp) | push/pop front/back (sentinel node) | ✅ |
| Dynamic array | [dynamic_array.hpp](./src/data_structures/dynamic_array.hpp) | insert_at, remove_at, push/pop, resize | 🚧 resize, push_back, front, back, clear to do |
| Binary search tree | [bst.hpp](./src/data_structures/bst.hpp) | insert, remove, search, min/max, height, in_order | ✅ |
| Graph (adjacency list) | [graph.hpp](./src/data_structures/graph.hpp) | add/remove vertex & edge, DFS, BFS, shortest path | 🚧 shortest_path to do |
| Stack | [stack.hpp](./src/data_structures/stack.hpp) | push, pop, top (linked nodes) | 🚧 not started |
| Queue | [queue.hpp](./src/data_structures/queue.hpp) | push, pop, front, back (circular buffer) | 🚧 not started |
| Min-heap / priority queue | [min_heap.hpp](./src/data_structures/min_heap.hpp) | push, pop, top, build from vector | 🚧 not started |
| Hash map | [hash_map.hpp](./src/data_structures/hash_map.hpp) | put, get, contains, remove (separate chaining, rehash) | 🚧 not started |
| Trie | [trie.hpp](./src/data_structures/trie.hpp) | insert, search, starts_with | 🚧 not started |
| Union-find | [union_find.hpp](./src/data_structures/union_find.hpp) | find, unite, connected (path compression, union by rank) | 🚧 not started |
| Weighted graph | [weighted_graph.hpp](./src/data_structures/weighted_graph.hpp) | add_edge, Dijkstra, topological sort | 🚧 not started |
| AVL tree | [avl_tree.hpp](./src/data_structures/avl_tree.hpp) | insert, remove, contains, in_order (self-balancing) | 🚧 not started |
| LRU cache | [lru_cache.hpp](./src/data_structures/lru_cache.hpp) | get, put (hash map + doubly linked list) | 🚧 not started |

## Layout

```
src/data_structures/   data structures and "design a class" problems (e.g. LRU cache), one header each
src/algorithms/        algorithms
src/problems/          function-style interview problems
tests/                 same layout as src/, files named test_<name>.cpp
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
