cmake_minimum_required(VERSION 3.21)
project(catchTest)

set(CMAKE_CXX_STANDARD 14)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(inc)
add_executable(catchTest test/test.cpp test/test.hpp src/main.cpp inc/matrix.hpp inc/exception.hpp)
target_link_libraries (catchTest Eigen3::Eigen)


