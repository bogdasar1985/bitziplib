cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

option(TESTS "Build including tests" OFF)
option(EXAMPLES "Build including examples" OFF)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic -fno-exceptions -fno-rtti -ansi -pedantic")

add_subdirectory(extlibs)

add_subdirectory(src/huffman)

if(TESTS)
    add_subdirectory(tests)
endif()

if(EXAMPLES)
    add_subdirectory(examples/file_compressor)
endif()

