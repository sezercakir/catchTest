cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)
include_directories(inc)
add_executable(test src/lib.cpp inc/lib.hpp test/test_main.cpp test/test_main.hpp test/matcher.hpp)
