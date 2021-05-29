cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

set(CMAKE_CXX_FLAGS -pg)

add_library(priority_queue STATIC priority_queue.cpp priority_queue.hpp symbol.hpp)

add_executable(main main.cpp priority_queue)