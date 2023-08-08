add_executable(test1 test_mergesort.cpp)
target_link_libraries(test1 PUBLIC sort)

add_executable(test2 test_bubblesort.cpp)
target_link_libraries(test2 PUBLIC sort)