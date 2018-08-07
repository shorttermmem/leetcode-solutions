
message("[INFO] PROJECT_NAME = ${package_name}")
message("[INFO] CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

set(build_dir "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
message("[INFO] MAKE_DIRECTORY = ${build_dir}")
file(MAKE_DIRECTORY ${build_dir})

include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${build_dir}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${build_dir}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${build_dir}/${CMAKE_INSTALL_BINDIR})
#set(CMAKE_MODULE_PATH              ${CMAKE_CURRENT_SOURCE_DIR})
message("[INFO] CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("[INFO] CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("[INFO] CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("[INFO] CMAKE_CACHEFILE_DIR = ${CMAKE_CACHEFILE_DIR}")
message("[INFO] CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
message("[INFO] CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")

# Crucial for vscode cpp_tool to reference source code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Ensure portability
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Polices
set(CMAKE_POLICY_DEFAULT_CMP0054 NEW)

# Warnings
string(APPEND CMAKE_CXX_FLAGS -Wno-pragma-once-outside-header)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    # Enable share libraries in Windows
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif()