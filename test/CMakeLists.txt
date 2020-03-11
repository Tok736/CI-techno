cmake_minimum_required(VERSION 3.9)
project(tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../include)


add_executable(Google_Tests_run test.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main lib)

add_test(
        NAME Google_Tests_run
        COMMAND Google_Tests_run
)