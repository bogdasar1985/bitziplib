cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic -fno-exceptions -ansi -pedantic")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

include_directories(include)

add_library(dynamic_array STATIC dynamic_array.hpp dynamic_array.cpp)

add_library(hf_priority_queue STATIC hf_priority_queue.cpp hf_priority_queue.hpp symbol.hpp utility.hpp dynamic_array)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)

add_library(bitset STATIC bitset.hpp bitset.cpp)

add_library(huffman STATIC include/huffman.hpp huffman.cpp hf_priority_queue bitset)
