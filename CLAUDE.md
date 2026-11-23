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
```

There is no linter. `compile_commands.json` is exported to `build/`.

## Layout

```
src/data_structures/<name>.hpp           # one header per structure, flat (no sub-folders)
src/algorithms/<name>.hpp                # sorting, searching, graph algorithms (not started yet)
src/problems/<name>.hpp                  # interview problems built on the structures
tests/<same folder as src>/test_<name>.cpp
```

- The code is header-only. `src/` is the include root (CMake `INTERFACE` library `data_structures`), so includes look like `#include "data_structures/singly_linked_list.hpp"`.
- Keep folders flat; use descriptive file names instead of sub-folders. `tests/CMakeLists.txt` globs `test_*.cpp` recursively into one `ds_tests` executable linked with `GTest::gtest_main` (so no `main`). Re-run the configure step after adding a test file.
- **Only headers included by a test get compiled.** When starting a new structure, add its test file at the same time so compile errors show up.

## Conventions

- Each structure is a single self-contained class. There are no abstract interfaces and no `virtual`. Consistency comes from the conventions below, not from a base class.
- Node structs live in the same header as the structure that uses them (`Node` in `singly_linked_list.hpp`, `DNode` in `doubly_linked_list.hpp`, `BstNode` in `bst.hpp`).
- Every header starts with `#pragma once` and includes the standard headers it uses (`<cassert>`, `<optional>`, `<stdexcept>`, ...).
- Names are snake_case for methods and files, PascalCase for classes and node structs.
- Containers use names from the standard library: `size()`, `empty()`, `push_front/push_back`, `pop_front/pop_back`, `front()/back()`, `get(i)`/`operator[]`, `clear()`. The element counter member is `size_t count`.
- Classes are templates with every method defined inline in the class body (no out-of-line definitions), the way you'd write it in an interview. Public API comes first, then private members and helpers.
- `front()`/`back()` return `std::optional<T>`. Popping from an empty container throws `std::underflow_error`, and tests check it with `EXPECT_THROW`.
- GoogleTest suite names are `<ClassName>Test` (e.g. `SinglyLinkedListTest.PopFront`).
- Methods the owner hasn't written yet are stubs that `throw std::logic_error("<Class>::<method> not implemented")`, marked `// TODO: not implemented yet`, so the header compiles. Their tests are written in advance and fail until the owner implements them. Don't fill these in unless asked.
- Classes that own raw pointers delete their copy constructor and copy assignment.
- `Graph` is a non-template, **directed** adjacency-list graph over `int` vertices. Its methods are defined in the class body, so they need no `inline` keyword; if a non-template header ever defines a function outside a class, mark it `inline`. `is_connected()` means every vertex is reachable from vertex 0.
- `BinarySearchTree` keeps `parent` pointers up to date on insert and remove. `height()` and `depth()` count nodes, not edges (a single node has height 1 and the root has depth 1).
