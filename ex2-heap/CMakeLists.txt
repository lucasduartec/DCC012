
cmake_minimum_required(VERSION 3.14)
project(leftist-heap CXX)

include_directories(${PROJECT_SOURCE_DIR}/libheap/include)


enable_testing()
# add_subdirectory(libheap)
add_subdirectory(tests)

#add_test(
#       NAME Setup
#    COMMAND cmake -E remove -f dataset.bin && cmake -E touch dataset.bin
#)

add_test(
  NAME   TestInsert
  COMMAND $<TARGET_FILE:test1>
  )

add_test(
   NAME  TestFindMax
   COMMAND $<TARGET_FILE:test2> 
   )

add_test(
    NAME  TestRemoveMax
    COMMAND $<TARGET_FILE:test3> 
)

add_test(
    NAME  TestMerge
    COMMAND $<TARGET_FILE:test4> 
)
