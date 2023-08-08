
add_executable(test_list test_list.cc)
target_link_libraries(test_list PUBLIC hash)

add_executable(test_hash1 test_hash1.cc)
target_link_libraries(test_hash1 PUBLIC hash)

add_executable(test_hash2 test_hash2.cc)
target_link_libraries(test_hash2 PUBLIC hash)

add_executable(test_hash3 test_hash3.cc)
target_link_libraries(test_hash3 PUBLIC hash)