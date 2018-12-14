cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

### Hunter snapshot that will be used ###
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.73.tar.gz"
    SHA1 "6f1905165d1f2dec8cd807aa005fc91308333926"
    LOCAL # load `${CMAKE_CURRENT_LIST_DIR}/cmake/Hunter/config.cmake`
)

set(package_name "leetcode")
project(${package_name} VERSION 0.1.0 LANGUAGES CXX)

# Custom script search path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
include(CommonSetup)
include(CommonTools)

#-----------------------------------------------------------------------------
option(COVERAGE "Generate coveralls data" OFF)
option(HUNTER_BUILD_SHARED_LIBS "Build 3rd party libraries as shared by default" ON)

hunter_add_package(gflags)
hunter_add_package(glog)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

#-----------------------------------------------------------------------------
add_subdirectory(src)

#-----------------------------------------------------------------------------
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
    hunter_add_package(GTest)
    find_package(GTest CONFIG REQUIRED)
    find_package(GMock CONFIG REQUIRED)
    include(CTest)
    add_subdirectory(test)

    hunter_add_package(benchmark)
    find_package(benchmark CONFIG REQUIRED)
    add_subdirectory(bench)
endif()

#-----------------------------------------------------------------------------
option(BUILD_DOC "Build docs" ON)
if(BUILD_DOC)
    add_subdirectory(doc)
endif()

#-----------------------------------------------------------------------------
option(BUILD_PACKING "Build package" ON)
if(BUILD_PACKING)
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
endif()