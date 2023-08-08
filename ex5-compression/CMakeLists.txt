cmake_minimum_required(VERSION 3.15)

project(compression)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(compression STATIC
             ${CMAKE_CURRENT_SOURCE_DIR}/src/lz77.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/huffman.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/lz78.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/common.cpp
             ${CMAKE_CURRENT_SOURCE_DIR}/src/lzw.cpp
          )

add_executable(test_lz77 test_lz77.cpp)
target_link_libraries(test_lz77 compression)

add_executable(test_huffman test_huffman.cpp)
target_link_libraries(test_huffman compression)

add_executable(test_lz78 test_lz78.cpp)
target_link_libraries(test_lz78 compression)


add_executable(test_lzw test_lzw.cpp)
target_link_libraries(test_lzw compression)

