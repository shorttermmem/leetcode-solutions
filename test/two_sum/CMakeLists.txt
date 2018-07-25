# Set name / sources / headers
get_current_folder_name(FOLDER_NAME)
set(TEST_TARGET_NAME ${FOLDER_NAME}_test)

set(${FOLDER_NAME}_SRC
    two_sum_test.cpp    
)

set(${FOLDER_NAME}_HDR
)

# Compiler
add_executable(${TEST_TARGET_NAME} 
    ${${FOLDER_NAME}_SRC} 
    ${${FOLDER_NAME}_HDR}
)

# Linker
target_link_libraries(
    ${TEST_TARGET_NAME}
    two_sum
    GMock::main
    )

add_test(
    NAME ${TEST_TARGET_NAME}
    COMMAND ${TEST_TARGET_NAME}
    WORKING_DIRECTORY $<TARGET_FILE_DIR:${TEST_TARGET_NAME}>
  )
