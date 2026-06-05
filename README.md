# Data Structures in C++

C++17 Data Structures implementations with Google Test and CMake.

## Structures

| Data structure | Header                            | Key operations                     |
|----------------|-----------------------------------|------------------------------------|
| List    | [ilist.hpp](./include/data_structures/ilist.hpp) | push_front, push_back, pop_front, pop_back   |



## Build & run tests

```bash
cmake -B build -DBUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## Requirements

- CMake ≥ 3.14
- C++17 compiler (GCC 9+, Clang 10+)
- GoogleTest is fetched automatically