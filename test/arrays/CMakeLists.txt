# Set name / sources / headers
get_current_folder_name(FOLDER_NAME)
set(TEST_TARGET_NAME test_${FOLDER_NAME})

set(${FOLDER_NAME}_SRC
    test_arrays.cpp 
)

# Compiler
add_executable(${TEST_TARGET_NAME} 
    ${${FOLDER_NAME}_SRC}
)

# Linker
target_link_libraries(${TEST_TARGET_NAME}
PUBLIC  leetcode
PRIVATE gflags
PRIVATE GMock::gmock #imply GTest::gtest
)

target_include_directories(${TEST_TARGET_NAME} 
PRIVATE
   "${CMAKE_CURRENT_LIST_DIR}"
)

add_test(
NAME ${TEST_TARGET_NAME}
COMMAND ${TEST_TARGET_NAME}
WORKING_DIRECTORY $<TARGET_FILE_DIR:${TEST_TARGET_NAME}>
)
