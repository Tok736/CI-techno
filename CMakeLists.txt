cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME CI-techno)
project(${PROJECT_NAME})


SET(CMAKE_C_FLAGS  "-lm")
set(CMAKE_C_STANDARD 11)

include_directories(include)



add_library(lib STATIC src/tetra.c)

add_executable(${PROJECT_NAME} src/main.c)
#add_executable(${PROJECT_NAME} src/tetra.c test/test.cpp)
target_link_libraries(${PROJECT_NAME} lib m)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(test)
#include googletest/include dir
include_directories(googletest/googletest/include)

#include the googlemock/include dir
include_directories(googletest/googlemock/include)


#Link with GoogleTest
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

#Link with GoogleMock
target_link_libraries(${PROJECT_NAME} gmock gmock_main)