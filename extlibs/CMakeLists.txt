cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wstrict-aliasing -Wpedantic -fno-exceptions -fno-rtti -ansi -pedantic")

add_library(bitset STATIC bitset.hpp bitset.cpp)

add_library(dynamic_array STATIC dynamic_array.hpp dynamic_array.cpp)