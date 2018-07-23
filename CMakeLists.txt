cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

### Hunter snapshot that will be used ###
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.0.tar.gz"
    SHA1 "4c27150185a31de4f65cfbb787c9561473c5b435"
)

set(package_name "leetcode")
project(${package_name} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_DEFAULT_CMP0048 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0046 NEW)

option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

# External & Setup
include(cmake/utilities.cmake)

### Download dependencies ###
hunter_add_package(GTest)
hunter_add_package(gflags)
hunter_add_package(glog)
hunter_add_package(benchmark)

### Find dependencies ###
find_package(GTest CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

include(cmake/setup.cmake)

# Configure run-path dependent libraries
option(ENABLE_RPATH "Enable RPATH for this library" ON)
mark_as_advanced(ENABLE_RPATH)
include(cmake/AddInstallRPATHSupport.cmake)
add_install_rpath_support(BIN_DIRS "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}"
                          LIB_DIRS "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}"
                          INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}"
                          DEPENDS ENABLE_RPATH
                          USE_LINK_PATH)

if(NOT CMAKE_CONFIGURATION_TYPES)
    if(NOT CMAKE_BUILD_TYPE)
        message(STATUS "Setting build type to 'Debug' as none was specified.")
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY VALUE "Debug")
    endif()
endif()             

#[[ Generate cmake configure files used by find_package(${PROJECT_NAME})
include(cmake/InstallBasicPackageFiles.cmake)
install_basic_package_files(${PROJECT_NAME}
                            VERSION ${${PROJECT_NAME}_VERSION}
                            COMPATIBILITY AnyNewerVersion
                            TARGETS_PROPERTY ${PROJECT_NAME}_TARGETS
                            VARS_PREFIX ${PROJECT_NAME}
                            NO_CHECK_REQUIRED_COMPONENTS_MACRO
                            DEPENDENCIES gflags glog googletest)
]]
# Add the uninstall target
include(cmake/AddUninstallTarget.cmake)

###############################
add_subdirectory(src)

option(BUILD_TESTING "Create tests using CMake" ON)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()

option(BUILD_DOC "Build documentation" ON)
if(BUILD_DOC)
    add_subdirectory(doc)
endif()
###############################

# Packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#print_cmake_variables()
