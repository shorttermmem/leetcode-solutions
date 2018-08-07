set(LIBRARY_TARGET_NAME leetcode)

list(APPEND CORE_SRC
"${CMAKE_CURRENT_LIST_DIR}/core/factoryImpl.cpp"
"${CMAKE_CURRENT_LIST_DIR}/core/factoryImpl.h"
)

list(APPEND CORE_HDR
"${CMAKE_CURRENT_LIST_DIR}/core"
)

include(arrays/CMakeLists.txt)
add_library(${LIBRARY_TARGET_NAME} SHARED "")

set_target_properties(${LIBRARY_TARGET_NAME} 
PROPERTIES 
    VERSION ${${PROJECT_NAME}_VERSION} SOVERSION 1
)

# List make & make install files.
target_include_directories(${LIBRARY_TARGET_NAME} 
PUBLIC 
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include;${PROJECT_SOURCE_DIR}/include/categories;${${COMPONENT_NAME}_HDR}>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_TARGET_NAME}>"
)

# List IDE source files.
target_sources(${LIBRARY_TARGET_NAME}
PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/categories"
    "${${COMPONENT_NAME}_HDR}"
    "${CORE_HDR}"
PRIVATE
    "${${COMPONENT_NAME}_SRC}"
    "${CORE_SRC}"
)

target_link_libraries(${LIBRARY_TARGET_NAME} 
PUBLIC 
    glog::glog
)

# Export no symbols by default (if the compiler supports it).
# This makes e.g. GCC's "visibility behavior" consistent with MSVC's. 
# On Windows/MSVC this is a noop.
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# generate export header automatically
include (GenerateExportHeader)
GENERATE_EXPORT_HEADER(${LIBRARY_TARGET_NAME}
    BASE_NAME shared
    EXPORT_MACRO_NAME SHARED_EXPORT
    EXPORT_FILE_NAME "${PROJECT_SOURCE_DIR}/include/shared_EXPORTS.h"
)

add_subdirectory(search_autocomplete_system)