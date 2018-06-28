cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

set( package_name "leetcode" )
project(${package_name} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POLICY_DEFAULT_CMP0048 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0046 NEW)

include(cmake/external.cmake)

# Setup after external
include(cmake/setup.cmake)

add_subdirectory(two_sum)
add_subdirectory(search_autocomplete_system)

#[[
if(NOT TARGET doc)
  add_custom_target(doc)
  add_dependencies(doc twosum)
endif()
]]

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#include(cmake/debug.cmake)
