cmake_minimum_required(VERSION 3.10)
project(string-matching)
include_directories(src)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main stringmatching)

add_executable(desempenho desempenho.cpp)
target_link_libraries(desempenho stringmatching)
