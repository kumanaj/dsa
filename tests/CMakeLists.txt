# Every tests/**/test_*.cpp is picked up automatically (re-run cmake after adding a file).
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp)

add_executable(ds_tests ${TEST_SOURCES})
target_link_libraries(ds_tests PRIVATE data_structures GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ds_tests)
