cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
include_directories(inc)
include_directories(../google_test_lib/googletest-release-1.10.0/googletest/include)

#find_library(GTEST
#        NAMES "gtest"
#        PATHS ${PROJECT_SOURCE_DIR}/google_test_lib/googletest-main/googletest/build
#        NO_DEFAULTH_PATH)

add_executable(google_test_example "test/test1_.cpp")

#target_link_libraries(google_test_example ${GTEST})

