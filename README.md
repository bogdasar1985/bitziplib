# HuffmanCodeLib
HuffmanCodeLib is a C++ library for work with huffman algorithm

* C++ 98
* No Exceptions
* No STL
* No RTTI

# How to build a library
Inside a library directory
```
mkdir build && cd build

cmake ..

make -j4
```
Use `-DTESTS=1` option to build with tests. (Require Catch2)

Use `-DEXAMPLES=1` option to build with examples.

# How to use via CMake
```cmake
include_directories(${PATH to /include})

add_executable(main main.cpp)

target_link_directories(main PUBLIC ${PATH to /lib})

target_link_libraries(main huffman bitset)
```
---------------
NOTE: Documentation, Contributing Guidelines and Coding Standarts are coming soon!
