# Coding Interview Practice (C++)

C++17 data structures and LeetCode problems for interview practice, built with CMake and tested with GoogleTest.

## What's inside

| Area | Where | Progress |
|---|---|---|
| Data structures | [src/data_structures](./src/data_structures/README.md) | 3 / 14 done |
| Blind 75 problems, grouped by NeetCode pattern | [src/problems](./src/problems/README.md) | 3 / 75 solved |

Each area's README has the full checklist and how to run its tests.

## Layout

```
src/data_structures/   one header per structure (also "design a class" problems like the LRU cache)
src/problems/          LeetCode problems, one folder per NeetCode pattern; common/ has ListNode/TreeNode
tests/                 same layout as src/, files named test_<name>.cpp
```

## Build & test

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DENABLE_ASAN=OFF
cmake --build build
ctest --test-dir build --output-on-failure
```

### Running a subset

```bash
ctest --test-dir build -L data_structures --output-on-failure            # all data structures
./build/tests/ds_tests --gtest_filter='StackTest.*'                      # one data structure

ctest --test-dir build -L problems                                       # every problem
ctest --test-dir build -L trees --output-on-failure                      # one pattern
./build/tests/problems_07_trees --gtest_filter='InvertBinaryTreeTest.*'  # one problem
```

`ctest -L` matches labels as a regex, so any pattern folder name without its number works (`two_pointers`, `1d_dp`, `intervals`, ...).

To enable AddressSanitizer, set `ENABLE_ASAN=ON`. New `test_*.cpp` files and folders are picked up after re-running the configure step.

## Requirements

- CMake ≥ 3.14
- C++17 compiler (GCC 9+, Clang 10+)
- GoogleTest is fetched automatically.
