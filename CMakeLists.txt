cmake_minimum_required(VERSION 3.0.0)
project(plugin_test VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

add_executable(plugin_test main.cpp)
add_library(plugin_a SHARED plugin_a.cpp)
add_library(plugin_b SHARED plugin_b.cpp)
add_library(plugin_evil SHARED plugin_evil.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
