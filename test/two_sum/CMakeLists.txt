# Set name / sources / headers
get_current_folder_name(FOLDER_NAME)
set(TEST_TARGET_NAME ${FOLDER_NAME}_test)

set(${TEST_TARGET_NAME}_SRC
    two_sum_test.cpp    
)

set(${TEST_TARGET_NAME}_HDR
)

# Compiler
add_executable(${TEST_TARGET_NAME} 
    ${${TEST_TARGET_NAME}_SRC} 
    ${${TEST_TARGET_NAME}_HDR}
)

# Linker
target_link_libraries(
    ${TEST_TARGET_NAME}
    two_sum
    gtest_main
    )

#
add_test(
    NAME ${TEST_TARGET_NAME}
    COMMAND ${TEST_TARGET_NAME}
    WORKING_DIRECTORY $<TARGET_FILE_DIR:${TEST_TARGET_NAME}>
  )
