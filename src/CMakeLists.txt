set(LIBRARY_TARGET_NAME leetcode)

list(APPEND PUBLIC_HDR
"${PROJECT_SOURCE_DIR}/include/factory.h"
"${PROJECT_SOURCE_DIR}/include/platform.h"
"${PROJECT_SOURCE_DIR}/include/solver.h"
"${PROJECT_SOURCE_DIR}/include/version.h"
"${PROJECT_SOURCE_DIR}/include/component/arraysolver.h"
)

list(APPEND PRIVATE_SRC
"${CMAKE_CURRENT_LIST_DIR}/core/factoryimpl.cpp"
"${CMAKE_CURRENT_LIST_DIR}/impl/arraysolver.cpp"
)

list(APPEND PRIVATE_HDR
"${CMAKE_CURRENT_LIST_DIR}/core/factoryimpl.h"
)

add_library(${LIBRARY_TARGET_NAME} SHARED "")

set_target_properties(${LIBRARY_TARGET_NAME} 
PROPERTIES 
    VERSION ${${PROJECT_NAME}_VERSION} SOVERSION 1
)

# List make & make install files.
target_include_directories(${LIBRARY_TARGET_NAME} 
PUBLIC 
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include;${PROJECT_SOURCE_DIR}/include/component;>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_TARGET_NAME}>"
)

# List IDE source files.
target_sources(${LIBRARY_TARGET_NAME}
PUBLIC
    "${PUBLIC_HDR}"
    "${PRIVATE_HDR}"
PRIVATE
    "${PRIVATE_SRC}"
)

# List IDE folder structure.
source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${PUBLIC_HDR})
source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${PRIVATE_SRC} ${PRIVATE_HDR})

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

# Unix use RPATH, no install required.
if(MSVC)
  # Install libraries manually (workaround for cpack)
  # See: http://public.kitware.com/Bug/view.php?id=15400
  foreach(DEPS glog::glog)
    add_custom_command(TARGET ${LIBRARY_TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:${DEPS}>
            $<TARGET_FILE_DIR:${LIBRARY_TARGET_NAME}>)
  endforeach()
endif()


add_subdirectory(search_autocomplete_system)