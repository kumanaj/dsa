add_executable(ds_tests
    test_linked_list.cpp
)

target_link_libraries(ds_tests PRIVATE data_structures GTest::gtest_main)
target_include_directories(ds_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(ds_tests)
