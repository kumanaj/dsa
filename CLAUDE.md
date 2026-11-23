# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Working agreement

This repo is the owner's coding-interview practice. **The owner writes every data structure and algorithm implementation themselves.** Do not write, complete or rewrite method bodies unless explicitly asked. If you spot a bug, name it with `file:line` and say why it's wrong, but leave the fix to them. You can help with structure, naming consistency, CMake/test scaffolding, include guards and empty stubs. Keep everything simple and readable, in the style of interview code rather than a production library.

## Commands

C++17, CMake ≥ 3.14. GoogleTest v1.14.0 is fetched by `FetchContent` (`cmake/FetchGoogleTest.cmake`), so the first configure needs network access.

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DENABLE_ASAN=OFF   # ENABLE_ASAN=ON for AddressSanitizer
cmake --build build
ctest --test-dir build --output-on-failure

# Single test / suite
ctest --test-dir build -R 'SinglyLinkedListTest.PushFront' --output-on-failure
./build/tests/ds_tests --gtest_filter='DoublyLinkedListTest.*'

# By label (ctest -L is a regex): data_structures, problems, or one pattern
ctest --test-dir build -L arrays_hashing --output-on-failure
./build/tests/problems_01_arrays_hashing --gtest_filter='TwoSumTest.*'
```

There is no linter. `compile_commands.json` is exported to `build/`.

## Layout

```
src/data_structures/<name>.hpp           # one header per structure, flat (no sub-folders)
src/algorithms/<name>.hpp                # sorting, searching, graph algorithms (not started yet)
src/problems/<NN_pattern>/<NNNN>_<title>.hpp   # LeetCode problems (Blind 75, later NeetCode 150), see below
tests/<same folder as src>/test_<name>.cpp
```

- The code is header-only. `src/` is the include root (CMake `INTERFACE` library `data_structures`), so includes look like `#include "data_structures/singly_linked_list.hpp"`.
- Keep `data_structures/` flat; use descriptive file names instead of sub-folders. `problems/` is the exception: one sub-folder per pattern.
- `tests/CMakeLists.txt` builds `tests/data_structures/` into one `ds_tests` executable (label `data_structures`), and each `tests/problems/<NN_pattern>/` folder into its own `problems_<NN_pattern>` executable (label `problems_<pattern>`). All link `GTest::gtest_main` (so no `main`). Re-run the configure step after adding a test file or a pattern folder.
- **Only headers included by a test get compiled.** When starting a new structure, add its test file at the same time so compile errors show up.
- READMEs: the root `README.md` is a short landing page (what's inside with progress counts, layout, build/test). Each area keeps its own checklist: `src/data_structures/README.md` (✅ done · 🚧 partly done · ⬜ not started) and `src/problems/README.md`. When a status changes, update the area's README and the count in the root README.

## Conventions

- Each structure is a single self-contained class. There are no abstract interfaces and no `virtual`. Consistency comes from the conventions below, not from a base class.
- Node structs live in the same header as the structure that uses them and each has a unique name (`Node`, `DNode`, `BstNode`, `StackNode`, `HashNode`, `TrieNode`, `AvlNode`, `WeightedEdge`, `LruNode`), because two different structs with the same name in one test binary break the one-definition rule.
- Every header starts with `#pragma once` and includes the standard headers it uses (`<cassert>`, `<optional>`, `<stdexcept>`, ...).
- Names are snake_case for methods and files, PascalCase for classes and node structs.
- Containers use names from the standard library: `size()`, `empty()`, `push_front/push_back`, `pop_front/pop_back`, `front()/back()`, `get(i)`/`operator[]`, `clear()`. The element counter member is `size_t count`; structures backed by a `std::vector` use its size instead. Stack, queue and heap use `push`/`pop`/`top` or `front`/`back` like `std::stack`, `std::queue` and `std::priority_queue`.
- Classes (templates where the element type varies) have every method defined inline in the class body (no out-of-line definitions), the way you'd write it in an interview. Public API comes first, then private members and helpers.
- `front()`/`back()` return `std::optional<T>`. Popping from an empty container throws `std::underflow_error`, and tests check it with `EXPECT_THROW`.
- GoogleTest suite names are `<ClassName>Test` (e.g. `SinglyLinkedListTest.PopFront`).
- Methods the owner hasn't written yet are stubs that `throw std::logic_error("<Class>::<method> not implemented")`, marked `// TODO: not implemented yet`, so the header compiles. Their tests are written in advance and fail until the owner implements them. Don't fill these in unless asked.
- Classes that own raw pointers delete their copy constructor and copy assignment.
- Items and keys are passed as `const T&` in the public API. Single-argument constructors are `explicit`. Data members and internal helpers (`resize`, `dfs_helper`, `*_node` recursion) are `private` (nothing inherits, so no `protected`).
- A destructor must not call a stub (a throw from a destructor terminates the whole test run). Until `clear()` is written, the destructor holds a `// TODO` comment instead and leaks, so expect LeakSanitizer reports with `ENABLE_ASAN=ON`.
- `Graph` is a non-template, **directed** adjacency-list graph over `int` vertices. Its methods are defined in the class body, so they need no `inline` keyword; if a non-template header ever defines a function outside a class, mark it `inline`. `is_connected()` means every vertex is reachable from vertex 0.
- `BinarySearchTree` keeps `parent` pointers up to date on insert and remove. `height()` and `depth()` count nodes, not edges (a single node has height 1 and the root has depth 1). It keeps duplicate keys (they go right), tracks `size_t count` so `size()` is O(1), and exposes `in_order()` returning a `std::vector<T>` instead of printing.
- `AvlTree` has no parent pointers, ignores duplicate keys, and stores each node's `height` counting nodes like `BinarySearchTree`.
- `WeightedGraph` is directed like `Graph` and throws `std::out_of_range` for invalid vertices. `dijkstra()` returns `WeightedGraph::INF` for unreachable vertices; `topological_sort()` returns `std::nullopt` on a cycle.
- `Trie` handles lowercase `a`-`z` only.
- `LruCache` has `int` keys and values, and `get()` returns `std::optional<int>`.

## Problems (`src/problems/`)

- **The owner writes every solution.** Problem files are stubs; never fill in a `Solution` unless explicitly asked.
- Folders follow the category order of NeetCode's Blind 75 page: `01_arrays_hashing`, `02_two_pointers`, `03_sliding_window`, `04_binary_search`, `05_linked_list`, `06_stack`, `07_trees`, `08_tries`, `09_backtracking`, `10_heap`, `11_graphs`, `12_advanced_graphs`, `13_1d_dp`, `14_2d_dp`, `15_greedy`, `16_intervals`, `17_bit_manipulation`, `18_math_geometry`. NeetCode 150 problems go into the same folders.
- File name: 4-digit LeetCode number + snake_case title, e.g. `0001_two_sum.hpp`; test file `test_0001_two_sum.cpp`.
- Deliberate exception to the naming rules above: each problem is LeetCode's own shape, `class Solution` with the camelCase method and LeetCode's parameter types, so it can be pasted into LeetCode. It is wrapped in `namespace lc<NNNN>` so the many `Solution` classes don't violate the one-definition rule. The stub throws `std::logic_error("lc<NNNN>::<method> not implemented")` and is marked `// TODO: not implemented yet`. Only `<stdexcept>` and the headers the signature needs are included, so the includes don't hint at the approach.
- Header comment block: number, title, difficulty, LeetCode link (plus a free NeetCode link for Premium problems), lists, pattern, the problem summarised in our own words (don't copy LeetCode's text), examples, constraints, follow-up, and an empty "My notes" block (Approach / Time / Space).
- Tests: 2–3 per problem, suite `<ProblemTitle>Test` (e.g. `TwoSumTest.Example1`), using the LeetCode examples plus one edge case. When LeetCode accepts answers in any order, the test sorts before comparing. Check new tests against a throwaway reference solution outside the repo before adding them.
- `problems/common/list_node.hpp` and `tree_node.hpp` define LeetCode's `ListNode`/`TreeNode` exactly as LeetCode does (global, shared by every problem) plus test helpers: `build_list`/`to_vector`/`free_list`, and `build_tree`/`to_level_order`/`find_node`/`free_tree` with `null` for LeetCode's level-order format. Types used by only one problem (`Node` in 133, `Interval` in 252/253) live inside that problem's namespace.
- Design problems use LeetCode's class name instead of `Solution` (`Trie`, `WordDictionary`, `MedianFinder`, `Codec`); their constructor is a throwing stub too. Premium problems (252, 253, 261, 269, 271, 323) use the signature of NeetCode's free version and link it.
- Tests free everything they allocate, so the problem tests are clean under AddressSanitizer given a non-leaking solution.
- `src/problems/README.md` holds the Blind 75 checklist; keep it in sync when scaffolding or when the owner says a problem is solved.
