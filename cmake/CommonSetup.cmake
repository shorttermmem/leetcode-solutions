
message("[INFO] PROJECT_NAME = ${package_name}")
# for single-configuration generators (make and ninja)
message("[INFO] CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")

set(build_dir "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
message("[INFO] MAKE_DIRECTORY = ${build_dir}")
file(MAKE_DIRECTORY ${build_dir})

include(GNUInstallDirs)

if(WIN32)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${build_dir}${CMAKE_INSTALL_BINDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${build_dir}${CMAKE_INSTALL_BINDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${build_dir}${CMAKE_INSTALL_BINDIR})
else()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${build_dir}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${build_dir}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${build_dir}/${CMAKE_INSTALL_BINDIR})
endif()
message("[INFO] CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("[INFO] CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("[INFO] CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("[INFO] CMAKE_CACHEFILE_DIR = ${CMAKE_CACHEFILE_DIR}")
message("[INFO] CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
message("[INFO] CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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

####################################################################
# Benchmark & test options
if (ENABLE_FRAME_POINTER)
    # disable frame pointer omission
    if (MSVC)
        add_compile_options(/Oy-)
    else ()
        add_compile_options(-fno-omit-frame-pointer)
    endif ()
endif ()

 # Enable Address Sanitizer
if (ENABLE_ASAN)
    add_compile_options(-fsanitize=address)
    #add_linker_flags(-fsanitize=address)
endif ()

####################################################################

# Warnings
if(WIN32)
  if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    # Enable share libraries in Windows
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
  elseif(CYGWIN OR MINGW)
    # NOT USED
    message(FATAL_ERROR "CYGWIN or MINGW not supported")
  endif()
elseif(UNIX)
  if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
    string(APPEND CMAKE_CXX_FLAGS -Wno-pragma-once-outside-header)
  else()
    # NOT USED
  endif()
endif()