cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

### Hunter snapshot that will be used ###
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.0.tar.gz"
    SHA1 "4c27150185a31de4f65cfbb787c9561473c5b435"
)

set(package_name "leetcode")
project(${package_name} VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

#-----------------------------------------------------------------------------
hunter_add_package(GTest)
hunter_add_package(gflags)
hunter_add_package(glog)
hunter_add_package(benchmark)

find_package(GTest CONFIG REQUIRED)
find_package(GMock CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

#-----------------------------------------------------------------------------
include(cmake/CommonTools.cmake)
include(cmake/CommonSetup.cmake)

add_subdirectory(src)

#-----------------------------------------------------------------------------
option(BUILD_TESTING "Build tests using CMake" ON)
if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(test)
    add_subdirectory(bench)
endif()

#-----------------------------------------------------------------------------
option(BUILD_DOC "Build documentation" ON)
if(BUILD_DOC)
    add_subdirectory(doc)
endif()

#-----------------------------------------------------------------------------
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
#print_cmake_variables()
