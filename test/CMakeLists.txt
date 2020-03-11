cmake_minimum_required(VERSION 3.15)
project(tests)

find_package(GTest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../include)


add_executable(tests test.cpp)

target_link_libraries(tests gtest gtest_main lib)

add_test(
        NAME runTest
        COMMAND runTest
)