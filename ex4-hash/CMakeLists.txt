
cmake_minimum_required(VERSION 3.14)
project(dcc012-hash-1)

include_directories(${PROJECT_SOURCE_DIR}/hash/include)

add_subdirectory(hash)


add_executable(performance performance.cc)
target_link_libraries(performance hash)


enable_testing()
add_subdirectory(tests)

add_test(NAME test_list COMMAND test_list)
add_test(NAME divisao COMMAND test_hash1)
add_test(NAME multiplicacao COMMAND test_hash2)
add_test(NAME my_hash COMMAND test_hash3)









    
