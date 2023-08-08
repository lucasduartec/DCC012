
file(GLOB source_files src/*.cc include/*.h)
add_library(libheap ${source_files})
target_include_directories(libheap PUBLIC ${PROJECT_SOURCE_DIR}/include)

