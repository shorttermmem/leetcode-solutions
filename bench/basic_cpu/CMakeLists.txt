# Set name / sources / headers
get_current_folder_name(FOLDER_NAME)
set(BENCH_TARGET_NAME ${FOLDER_NAME}_bench)

set(${FOLDER_NAME}_SRC
    cpu_1.cc  
)

set(${FOLDER_NAME}_HDR
)

# Compiler
add_executable(${BENCH_TARGET_NAME} 
    ${${FOLDER_NAME}_SRC} 
    ${${FOLDER_NAME}_HDR}
)

# Linker
target_link_libraries(
    ${BENCH_TARGET_NAME}
    benchmark::benchmark
    )

add_test(
    NAME ${BENCH_TARGET_NAME}
    COMMAND ${BENCH_TARGET_NAME}
    WORKING_DIRECTORY $<TARGET_FILE_DIR:${BENCH_TARGET_NAME}>
  )