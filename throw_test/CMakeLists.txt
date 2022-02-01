cmake_minimum_required(VERSION 3.17)
project(throw_test)

set(CMAKE_CXX_STANDARD 14)
include_directories(inc)
add_executable(throw_test test/test_main.cpp test/test_main.hpp inc/lib.hpp src/lib.cpp)
