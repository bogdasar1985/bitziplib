cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib_example)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic")

include_directories(../../include)

link_directories(../../lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(coder coder.cpp)

add_executable(decoder decoder.cpp)

target_link_libraries(coder huffman bitset)

target_link_libraries(decoder huffman bitset)