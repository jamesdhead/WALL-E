# cmake_minimum_required(VERSION <specify CMake version here>)
project(WALL_E)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES WALL-E.cpp WALL-E.h)
add_executable(WALL_E ${SOURCE_FILES})