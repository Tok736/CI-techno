cmake_minimum_required(VERSION 3.15)
project(CI-techno C)

SET(MYCOMPILE_FLAGS "-Werror -lm")
set(CMAKE_C_STANDARD 99)

add_executable(CI-techno src/main.c)
target_link_libraries(CI-techno m)
