add_executable(
    two_sum_test
    two_sum_test.cpp
    )

target_link_libraries(
    two_sum_test
    twosum
    gtest_main
    )

add_test(
    NAME unit
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/two_sum_test
  )
