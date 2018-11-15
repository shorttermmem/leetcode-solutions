# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# Test: Generates CTestTestfile.cmake for ctest app
enable_testing()
add_subdirectory(test_arraysolver)
add_subdirectory(test_stringsolver)
add_subdirectory(test_sortingsolver)