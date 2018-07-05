
include(cmake/DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             release-1.8.0
                 UPDATE_DISCONNECTED 1
                 QUIET
)
SET(BUILD_GTEST ON CACHE BOOL "")
SET(BUILD_GMOCK OFF CACHE BOOL "")
SET(gtest_build_tests OFF CACHE BOOL "")
SET(gtest_build_samples OFF CACHE BOOL "")
SET(gmock_build_tests ON CACHE BOOL "")
SET(gtest_force_shared_crt ON CACHE BOOL "")
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
# release-1.8.0 fails on VS2017
target_compile_definitions(gtest PRIVATE GTEST_HAS_TR1_TUPLE=0)
target_compile_definitions(gtest_main PRIVATE GTEST_HAS_TR1_TUPLE=0)

download_project(PROJ                gflags
                 GIT_REPOSITORY      https://github.com/gflags/gflags.git
                 GIT_TAG             v2.2.1
                 UPDATE_DISCONNECTED 1
                 QUIET
)
add_subdirectory(${gflags_SOURCE_DIR} ${gflags_BINARY_DIR})

download_project(PROJ                glog
                 GIT_REPOSITORY      https://github.com/google/glog
                 GIT_TAG             v0.3.5
                 UPDATE_DISCONNECTED 1
                 QUIET
)
add_subdirectory(${glog_SOURCE_DIR} ${glog_BINARY_DIR})