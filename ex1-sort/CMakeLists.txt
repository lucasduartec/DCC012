cmake_minimum_required(VERSION 3.16)

project(ex1-sort)

include_directories(include)

# add library
add_library(sort src/mergesort.cpp src/bubblesort.cpp)

add_subdirectory(tests)
