cmake_minimum_required (VERSION 3.5)
project (Simple)
set (CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

include_directories ("${PROJECT_SOURCE_DIR}/lib")

add_subdirectory (lib) 

add_compile_options("-Og")

add_executable(ltest ltest.cc)
add_executable(test_coding test_coding.cc)
target_link_libraries (ltest lib)
target_link_libraries (test_coding lib)

