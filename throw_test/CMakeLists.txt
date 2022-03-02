cmake_minimum_required(VERSION 3.17)
project(throw_test)

set(CMAKE_CXX_STANDARD 14)
#test
include_directories(test)
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp" "test/*.hpp")
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})


