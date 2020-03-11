cmake_minimum_required(VERSION 3.9)
project(tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../include)


add_executable(runTest test.cpp)

target_link_libraries(runTest gtest gtest_main lib)

add_test(
        NAME runTest
        COMMAND runTest
)