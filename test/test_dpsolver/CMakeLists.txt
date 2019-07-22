# Set name / sources / headers
get_current_folder_name(FOLDER_NAME)
set(TEST_TARGET_NAME ${FOLDER_NAME})

set(${FOLDER_NAME}_SRC
    main.cpp 
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
PRIVATE benchmark::benchmark
)

target_include_directories(${TEST_TARGET_NAME} 
PRIVATE
   "${COMMON_DIR}"
   "${CMAKE_CURRENT_LIST_DIR}"
)


# Unix use RPATH, no install required.
if(MSVC)
  # Install libraries manually (workaround for cpack)
  # See: http://public.kitware.com/Bug/view.php?id=15400
  foreach(DEPS gflags GMock::gmock)
    add_custom_command(TARGET ${TEST_TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:${DEPS}>
            $<TARGET_FILE_DIR:${TEST_TARGET_NAME}>)
  endforeach()
endif()

add_test(
NAME ${TEST_TARGET_NAME}
COMMAND ${TEST_TARGET_NAME}
WORKING_DIRECTORY $<TARGET_FILE_DIR:${TEST_TARGET_NAME}>
)
