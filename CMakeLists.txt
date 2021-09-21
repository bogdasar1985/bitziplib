cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic -fno-exceptions -fno-rtti -ansi -pedantic")

add_subdirectory(examples/file_compressor)

add_subdirectory(extlibs)

add_subdirectory(src/huffman)

add_subdirectory(tests)
