cmake_minimum_required(VERSION 3.10)
project(BitArrayTests)

set(CMAKE_CXX_STANDARD 17)

add_executable(BitArrayTests test_example.cpp BitArray_realization.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(BitArrayTests ${GTEST_LIBRARIES} pthread)
