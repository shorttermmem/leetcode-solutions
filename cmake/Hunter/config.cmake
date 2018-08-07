# Usage:
#   hunter_config(TARGET VERSION 1.0.0 CMAKE_ARGS 
#         BUILD_PACKAGE=OFF
#         BUILD_DOCS=OFF
#         BUILD_SHARED_LIBS=OFF
#         BUILD_TESTS=OFF)
include(hunter_config)

# Locally switch benchmark to static build.
hunter_config(benchmark VERSION 1.4.0 CMAKE_ARGS BUILD_SHARED_LIBS=OFF)