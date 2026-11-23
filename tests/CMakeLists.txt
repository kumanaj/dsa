include(GoogleTest)

# Data structures: every tests/data_structures/test_*.cpp goes into one executable, ds_tests.
file(GLOB_RECURSE DS_TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/data_structures/test_*.cpp)
add_executable(ds_tests ${DS_TEST_SOURCES})
target_link_libraries(ds_tests PRIVATE data_structures GTest::gtest_main)
gtest_discover_tests(ds_tests PROPERTIES LABELS data_structures)

# Problems: one executable per pattern folder, e.g. tests/problems/01_arrays_hashing/
# becomes problems_01_arrays_hashing with the label problems_arrays_hashing. ctest -L is a regex,
# so `ctest -L problems` runs every problem and `ctest -L arrays_hashing` runs one pattern.
# Re-run the configure step after adding a file or a new pattern folder.
file(GLOB PATTERN_DIRS LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR}/problems/*)
foreach(dir ${PATTERN_DIRS})
    if(IS_DIRECTORY ${dir})
        get_filename_component(pattern ${dir} NAME)
        file(GLOB PATTERN_SOURCES CONFIGURE_DEPENDS ${dir}/test_*.cpp)
        if(PATTERN_SOURCES)
            string(REGEX REPLACE "^[0-9]+_" "" label ${pattern})
            add_executable(problems_${pattern} ${PATTERN_SOURCES})
            target_link_libraries(problems_${pattern} PRIVATE data_structures GTest::gtest_main)
            gtest_discover_tests(problems_${pattern} PROPERTIES LABELS problems_${label})
        endif()
    endif()
endforeach()
