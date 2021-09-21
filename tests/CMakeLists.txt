cmake_minimum_required(VERSION 3.0)

project(HuffmanLibTests)

set(CMAKE_CXX_STANDARD 11)

find_package(Catch2 3 REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories(../include)

add_executable(main main.cpp ../include/huffman.hpp)

target_include_directories(main PUBLIC ../lib)

target_link_libraries(main PRIVATE Catch2::Catch2WithMain huffman)

