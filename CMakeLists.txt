cmake_minimum_required(VERSION 3.0)

project(HuffmanCodeLib)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_library(dynamic_array STATIC dynamic_array.hpp dynamic_array.cpp)

add_library(priority_queue STATIC priority_queue.cpp priority_queue.hpp symbol.hpp utility.hpp dynamic_array)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp priority_queue)

add_executable(bench_main bench_main.cpp)

target_link_libraries(bench_main benchmark pthread)