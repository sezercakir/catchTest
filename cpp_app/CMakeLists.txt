cmake_minimum_required(VERSION 3.17)
project(cpp_app)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/docs/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory(app)
add_subdirectory(lib)

add_compile_options( -Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)