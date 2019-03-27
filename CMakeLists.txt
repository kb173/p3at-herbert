cmake_minimum_required(VERSION 3.13)
project(p3at_herbert)

set(CMAKE_CXX_STANDARD 17)

add_library(p3at_herbert SHARED library.cpp library.h)