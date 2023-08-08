
file(GLOB source_files *.cc *.hh)
add_library(siga ${source_files})
target_include_directories(siga PUBLIC ${PROJECT_SOURCE_DIR}/src)
