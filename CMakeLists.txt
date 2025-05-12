cmake_minimum_required(VERSION 3.10)
project(linal_routines C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2")

add_subdirectory(src/)

include_directories(
    src/
    include/
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})