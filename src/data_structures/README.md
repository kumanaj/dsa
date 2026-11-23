# Data structures

Hand-written, header-only C++17 data structures. Each one is a single class in its own header, with tests in `tests/data_structures/test_<name>.cpp`. Unfinished methods are stubs that throw `std::logic_error`, so their tests fail until they're written.

## Running tests

```bash
cmake -B build && cmake --build build                    # re-run cmake after adding files
ctest --test-dir build -L data_structures --output-on-failure
./build/tests/ds_tests --gtest_filter='StackTest.*'      # one structure
```

## Progress

✅ done · 🚧 partly done · ⬜ not started

| | Data structure | Header | Key operations |
|---|---|---|---|
| ✅ | Singly linked list | [singly_linked_list.hpp](./singly_linked_list.hpp) | push/pop front/back, get, front, back, clear |
| ✅ | Doubly linked list | [doubly_linked_list.hpp](./doubly_linked_list.hpp) | push/pop front/back (sentinel node) |
| 🚧 | Dynamic array | [dynamic_array.hpp](./dynamic_array.hpp) | insert_at, remove_at, push/pop, resize. **To do:** resize, push_back, front, back, clear |
| ✅ | Binary search tree | [bst.hpp](./bst.hpp) | insert, remove, search, min/max, height, in_order |
| 🚧 | Graph (adjacency list) | [graph.hpp](./graph.hpp) | add/remove vertex & edge, DFS, BFS, shortest path. **To do:** shortest_path |
| ⬜ | Stack | [stack.hpp](./stack.hpp) | push, pop, top (linked nodes) |
| ⬜ | Queue | [queue.hpp](./queue.hpp) | push, pop, front, back (circular buffer) |
| ⬜ | Min-heap / priority queue | [min_heap.hpp](./min_heap.hpp) | push, pop, top, build from vector |
| ⬜ | Hash map | [hash_map.hpp](./hash_map.hpp) | put, get, contains, remove (separate chaining, rehash) |
| ⬜ | Trie | [trie.hpp](./trie.hpp) | insert, search, starts_with |
| ⬜ | Union-find | [union_find.hpp](./union_find.hpp) | find, unite, connected (path compression, union by rank) |
| ⬜ | Weighted graph | [weighted_graph.hpp](./weighted_graph.hpp) | add_edge, Dijkstra, topological sort |
| ⬜ | AVL tree | [avl_tree.hpp](./avl_tree.hpp) | insert, remove, contains, in_order (self-balancing) |
| ⬜ | LRU cache | [lru_cache.hpp](./lru_cache.hpp) | get, put (hash map + doubly linked list) |
