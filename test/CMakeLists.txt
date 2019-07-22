# Test: Generates CTestTestfile.cmake for ctest app
enable_testing()

set(COMMON_DIR "${CMAKE_CURRENT_LIST_DIR}/common")
add_subdirectory(test_arraysolver)
add_subdirectory(test_stringsolver)
add_subdirectory(test_dpsolver)