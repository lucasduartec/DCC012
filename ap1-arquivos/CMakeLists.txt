cmake_minimum_required(VERSION 3.14)
project(dcc012-lab1-arquivos)

option(CLASSROOM "Enable classroom build" OFF)

set(INPUT_DATA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests/data/")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h) 

include_directories(src)
add_subdirectory(src)
add_subdirectory(tests)


enable_testing()
add_test(NAME test1 COMMAND test1)
add_test(NAME test2 COMMAND test2)
add_test(NAME test3 COMMAND test3)
add_test(NAME test4 COMMAND test4)
add_test(NAME test5 COMMAND test5)
add_test(NAME test6 COMMAND test6)

set_tests_properties(test2 PROPERTIES DEPENDS "test1")
set_tests_properties(test3 PROPERTIES DEPENDS "test2")
set_tests_properties(test4 PROPERTIES DEPENDS "test3")
set_tests_properties(test5 PROPERTIES DEPENDS "test4")
set_tests_properties(test6 PROPERTIES DEPENDS "test5")
