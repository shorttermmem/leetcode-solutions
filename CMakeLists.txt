cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

### Hunter snapshot that will be used ###
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.0.tar.gz"
    SHA1 "4c27150185a31de4f65cfbb787c9561473c5b435"
)

set(package_name "leetcode")
project(${package_name} VERSION 0.1.0 LANGUAGES CXX)

#-----------------------------------------------------------------------------
option(HUNTER_BUILD_SHARED_LIBS "Build 3rd party libraries as shared" ON)

hunter_add_package(gflags)
find_package(gflags CONFIG REQUIRED)
hunter_add_package(glog)
find_package(glog CONFIG REQUIRED)

#-----------------------------------------------------------------------------
include(cmake/CommonTools.cmake)
include(cmake/CommonSetup.cmake)
add_subdirectory(src)

#-----------------------------------------------------------------------------
option(BUILD_TESTING "Build tests using CMake" ON)
if(BUILD_TESTING)
    hunter_add_package(GTest)
    hunter_add_package(benchmark)
    find_package(GTest CONFIG REQUIRED)
    find_package(GMock CONFIG REQUIRED)
    find_package(benchmark CONFIG REQUIRED)

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
option(BUILD_PACKING "Build packaging" ON)
if(BUILD_PACKING)
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
endif()