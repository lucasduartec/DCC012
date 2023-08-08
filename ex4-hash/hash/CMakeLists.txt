
file(GLOB source_files src/*.cc include/*.h)
add_library(hash ${source_files})
target_include_directories(hash PUBLIC ${PROJECT_SOURCE_DIR}/include)