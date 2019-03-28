cmake_minimum_required(VERSION 3.13)
project(p3at_herbert CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(p3at_herbert SHARED library.cpp library.h)

add_executable(tests tests.cpp)

include_directories("Aria/include")
include_directories("Catch2/single_include/catch2")

target_link_libraries(tests p3at_herbert)