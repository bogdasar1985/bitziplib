cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic -fno-exceptions -fno-rtti -ansi -pedantic")

add_library(hf_priority_queue hf_priority_queue.hpp hf_priority_queue.cpp)

target_link_libraries(hf_priority_queue dynamic_array bitset)

target_include_directories(hf_priority_queue PUBLIC ../../extlibs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../../lib)

add_library(huffman STATIC huffman.cpp ../../include/huffman.hpp)

target_link_libraries(huffman hf_priority_queue  bitset)

target_include_directories(huffman PUBLIC ../../include)