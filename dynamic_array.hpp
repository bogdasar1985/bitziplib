#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include <stdlib.h>
template <typename T>
class dynamic_array
{
public:
    dynamic_array();
    ~dynamic_array();
    void push_back(const T& sym);
    size_t size() const;
    T& operator[] (const size_t index);
    T* erase(const size_t index);
    void reserve(const size_t capacity);
private:
    T* array;
    size_t _size;
    size_t _capacity;
};
#include "dynamic_array.cpp"
#endif