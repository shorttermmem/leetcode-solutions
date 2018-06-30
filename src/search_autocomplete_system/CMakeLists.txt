# Set name / sources / headers
get_current_folder_name(EXE_TARGET_NAME)

set(${EXE_TARGET_NAME}_SRC
        main.cpp
)

# Compiler
add_executable(${EXE_TARGET_NAME} ${${EXE_TARGET_NAME}_SRC})

# Linker

# Installer
install(TARGETS ${EXE_TARGET_NAME} DESTINATION bin)