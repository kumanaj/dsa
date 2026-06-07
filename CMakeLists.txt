cmake_minimum_required(VERSION 3.14)
project(DataStructures VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build tests" ON)
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)

include(cmake/FetchGoogleTest.cmake)

add_subdirectory(src)

if(ENABLE_ASAN)
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g -O0)
    add_link_options(-fsanitize=address)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
