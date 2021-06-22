cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic -ansi -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_library(bitset STATIC bitset.hpp bitset.cpp)

add_library(dynamic_array STATIC dynamic_array.hpp dynamic_array.cpp)

add_library(priority_queue STATIC priority_queue.cpp priority_queue.hpp symbol.hpp utility.hpp dynamic_array)

add_library(huffman STATIC huffman.hpp huffman.cpp priority_queue bitset)

set(CMAKE_CXX_STANDARD 11)

add_executable(coder coder.cpp)

target_link_libraries(coder huffman bitset)

add_executable(bench_main bench_main.cpp)

target_link_libraries(bench_main benchmark pthread)